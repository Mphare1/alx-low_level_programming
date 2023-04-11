#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

static ssize_t read_file(char *file, char **buf, int fd);
static void write_copy(char *file, int fd, char *buf, int len);

/**
 * main - This main
 * @argc: count.
 * @argv: values.
 *
 * Return: 0
 */
static ssize_t read_file(char *file, char **buf, int fd)
{
	ssize_t read_len;
	char *temp_buf;

	temp_buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (temp_buf == NULL)
		exit(99);

	read_len = read(fd, temp_buf, BUFFER_SIZE);
	if (read_len < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	*buf = temp_buf;

	return (read_len);
}

static void write_copy(char *file, int fd, char *buf, int len)
{
	ssize_t write_len;
	int write_err;

	write_len = write(fd, buf, len);
	if (write_len < 0 || write_len != len)
	{
		write_err = (write_len < 0) ? 99 : 98;
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(write_err);
	}
}

int main(int argc, char *argv[])
{
	int src_fd, dest_fd;
	int close_err;
	char *buf, *src_file;
	char *dest_file;

	buf = NULL;
	int read_len = 1;
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp src_file dest_file\n");
		exit(97);
	}
	src_file = argv[1];
	dest_file = argv[2];
	src_fd = open(src_file, O_RDONLY);
	dest_fd = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while (read_len > 0)
	{
		read_len = read_file(src_file, &buf, src_fd);
		if (!read_len)
			break;
		write_copy(dest_file, dest_fd, buf, read_len);
	}

	free(buf);
	close_err = close(src_fd);
	if (close_err < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", src_fd);
		exit(100);
	}
	close_err = close(dest_fd);
	if (close_err < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", dest_fd);
		exit(100);
	}
	return (0);
}

