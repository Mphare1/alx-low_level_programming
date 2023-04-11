#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

static ssize_t read_file(char *file, char **buf, int fd);
static void write_copy(char *file, int fd, char *buf, int len);
/**
 * main - ............
 * @argc: c..........
 * @argv: ............
 *
 * Return: 0..........
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t rd_len = 1, close_err;
	char *buf = NULL, *file_from;
	char *file_to;
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = argv[1];
	
	file_to = argv[2];
	
	fd_from = open(file_from, O_RDONLY);
	
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		
		exit(98);
	}
	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	
	if (fd_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		
		exit(99);
	}
	while (rd_len > 0)
	{
		rd_len = read_file(file_from, &buf, fd_from);
		
		if (!rd_len)
			break;

		write_copy(file_to, fd_to, buf, rd_len);
	}

	free(buf);
	
	close_err = close(fd_from);
	
	if (close_err < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd_from);
		
		exit(100);
		
	}
	close_err = close(fd_to);
	if (close_err < 0)
	{
	
	dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd_to);
		
	exit(100);
	}
	return (0);
}

static ssize_t read_file(char *file, char **buf, int fd)
{
	ssize_t rd_len;
	
	char *tmp_buf11;

	tmp_buf = malloc(sizeof(char) * BUFFER_SIZE);
	
	if (tmp_buf11 == NULL)
		
		exit(99);

	rd_len = read(fd, tmp_buf11, BUFFER_SIZE);
	
	if (rd_len < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		
		exit(98);
	}
	*buf = tmp_buf11;

	return (rd_len);
}

static void write_copy(char *file, int fd, char *buf, int len)
{
	ssize_t wr_len1;
	
	int wr_err1;

	wr_len1 = write(fd, buf, len);
	
	if (wr_len1 < 0 || wr_len1 != len)
	{
		wr_err1 = (wr_len1 < 0) ? 99 : 98;
		
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		
		exit(wr_err1);
	}
}
