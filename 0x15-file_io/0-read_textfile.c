#include "main.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
* read_textfile - read a text file and print it
* 
* @filename: .......
* @letters: ... char to print.

* Return: .... chars printed.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_des = 0, erro = 0, read_c = 0;
char *buff = malloc(sizeof(char)*letters+1);
/****/
if (!filename || !letters)
{
return (0);
}
  file_des = open(filename, O_RDONLY);
  if (file_des < 0)
{
  return (0);
}
  if (!buff)
{
  return (0);
}
  read_c = read(file_des, buff, letters);
  if (read_c < 0)
  {
  free(buff);
  return (0);
  }
  buff[letters] = '\0';
  erro = write(STDOUT_FILENO, buff, read_c);
  if (erro <= 0)
  {
  free(buff);
  
return (0);
}

free(buff);
  
close(file_des);
  
return (read_c);
  
 
}
