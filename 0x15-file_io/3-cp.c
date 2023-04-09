#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

static ssize_t read_file(char *file, char **buf, int file_descriptor);
static void write_copy(char *file, int file_descriptor, char *buf, int len);

/**
 * main - This main
 * @ac: count.
 * @av: values.
 *
 * Return: 0
 */

int main(int ac, char *av[])
{
    int file_descriptor_0, file_descriptor_1, rd_len, err_code;
    char *buf, *file_from, *file_to;

    buf = NULL;
    rd_len = 1;
    if (ac != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
    file_from = av[1];
    file_to = av[2];
    file_descriptor_0 = open(file_from, O_RDONLY);
    file_descriptor_1 = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    while (rd_len > 0)
    {
        rd_len = read_file(file_from, &buf, file_descriptor_0);
        if (!rd_len)
            break;

        write_copy(file_to, file_descriptor_1, buf, rd_len);
    }

    free(buf);
    err_code = close(file_descriptor_0);
    if (err_code < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor_0);
        exit(100);
    }
    err_code = close(file_descriptor_1);
    if (err_code < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor_1);
        exit(100);
    }
    return (0);
}

/**
 * read_file - this reads a file into a buffer
 * @file: file to read
 * @buf: pointer.
 * @file_descriptor: file descriptors
 *
 * Return: size of the buffer.
 */
static ssize_t read_file(char *file, char **buf, int file_descriptor)
{
    int rd_len;

    if (file_descriptor < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
        exit(98);
    }
    if (!(*buf))
        *buf = malloc(sizeof(char) * BUFSIZE);
    if (!(*buf))
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
        exit(98);
    }
    rd_len = read(file_descriptor, *buf, BUFSIZE);
    if (rd_len < 0)
    {
        free(*buf);
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
        exit(98);
    }
    return (rd_len);
}

/**
 * write_copy - write the buffer.
 * @file: ...
 * @file_descriptor: file descriptors for the @file
 * @buf: pointer
 * @len: size of the buffer.
 */
static void write_copy(char *file, int file_descriptor, char *buf, int len)
{
  int err_code;
  if (file_descriptor < 0 || !buf)
{
    free(buf);
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
    exit(99);
}

int written = 0;
do {
    err_code = write(file_descriptor, buf + written, len - written);
    if (err_code < 0)
    {
        free(buf);
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
        exit(99);
    }
    written += err_code;
} while (written < len);
}
