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
int main(int argc, char *argv[])
{
	int fd1_in1, fd1_out1;
	int rd1_len1, close1_err1;
	char *buf1, *file1_from1;
	char *file1_to1;

	buf1 = NULL;
	rd1_len1 = 1;
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file1_from1 = argv[1];
	file1_to1 = argv[2];
	fd1_in1 = open(file1_from1, O_RDONLY);
	fd1_out1 = open(file1_to1, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while (rd_len > 0)
	{
		rd1_len1 = read_file(file1_from1, &buf1, fd1_in1);
		if (!rd1_len1)
			break;
		
		write_copy(file1_to1, fd1_out1, buf1, rd1_len1);
	}

	free(buf1);
	close_err = close(fd1_in1);
	if (close_err < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd_in);
		exit(100);
	}
	close1_err1 = close(fd_out);
	if (close1_err1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd_out);
		exit(100);
	}
	return (0);
}

/**
 * read_file - Reads a file
 * @file: the file to read
 * @buf: buffer
 * @fd: file...
 *
 * Return: bytes
 */
static ssize_t read_file(char *file, char **buf, int fd)
{
	ssize_t rd_len;
	char *tmp_buf;

	tmp_buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (tmp_buf == NULL)
		exit(99);

	rd_len = read(fd, tmp_buf, BUFFER_SIZE);
	if (rd_len < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	*buf = tmp_buf;

	return (rd_len);
}

/**
 * write_copy - Writes to file
 * @file: file to write to
 * @fd: file descript
 * @buf: buffer
 * @len: length
 *
 */
static void write_copy(char *file, int fd, char *buf, int len)
{
	ssize_t wr_len;
	int wr_err;

	wr_len = write(fd, buf, len);
	if (wr_len < 0 || wr_len != len)
	{
		wr_err = (wr_len < 0) ? 99 : 98;
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(wr_err);
	}
}
