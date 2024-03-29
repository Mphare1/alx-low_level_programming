#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <elf.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFERSIZE 1204

int _putchar(char c);
/*0-read_textfile.c*/
ssize_t read_textfile(const char *filename, size_t letters);
/*1-create_file.c*/
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
