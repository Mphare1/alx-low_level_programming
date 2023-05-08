#include "main.h"
/**
* read_textfile - Read a file and prints in POSIX stdout.
* @filename: File to be read.
* @letters: Number of letter to be read and print.
* Return: size of letters.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
    int f_opener= open(filename, O_RDONLY), size;
    char *buf = malloc(sizeof(char) * letters);
    
    if(!filename)
        return (0);
        
    if(!buf)
        return (0);      
        
    size = write(STDOUT_FILENO, buf, read(f_opener, buf, letters));
    if(f_opener == -1 || size == -1)
        return (0);
        
    close(f_opener);
    free(buf);
    return (size);
}
