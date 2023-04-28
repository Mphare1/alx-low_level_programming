#include "main.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - function that reads a text file and prints it to the POSIX
 * standard output.
 * @filename: pointer to the name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: number of letters actually read and printed, 0 if filename is NULL,
 * if file can not be opened, if memory allocation fails, if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int _fd, _errr, _rd;
	
	char *_buf;

	_fd = _errr = _rd = 0;
	if (!filename || !letters)
		return (0);
	
	_fd = open(filename, O_RDONLY);
	if (_fd < 0)
		return (0);

	_buf = malloc(sizeof(char) * letters + 1);
	
	if (!_buf)
		return (0);
	_rd = read(_fd, _buf, letters);
	if (_rd < 0)
	{
		free(buf);
		return (0);
	}
	_buf[letters] = '\0';
	
	errr = write(STDOUT_FILENO, _buf, _rd);
	if (errr <= 0)
	{
		free(_buf);
		return (0);
	}

	free(_buf);
	
	close(_fd);
	
	return (_rd);
}
