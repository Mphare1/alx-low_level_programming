#include "main.h"
#define BUFFERSIZE 1204
/**
  * main - Copies content.
  * @argc: Arguments count.
  * @argv: Files names.
  * Return: 0 on success
  */
int main(int argc, char **argv)
{
    int file_in, file_o, read_file, chk;
    char buffer[BUFFERSIZE];
    mode_t mode_file = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    if(argc != 3)
    
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
    file_in = open(argv[1], O_RDONLY);
    if(file_in == -1)
    
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
        
    file_o = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode_file);
    if(file_o == -1)
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
        
    read_file = chk = 1;
    while(read_file)
    {
        read_file = read(file_in, buffer, BUFFERSIZE);
        
        if(read_file == -1)
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
            
        if(read_file > 0)
        {
            chk = write(file_o, buffer, read_file);
            if(chk == -1)
                dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
        }
    }
    chk = close(file_in);
    if(chk == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_in), exit(100);
        
    chk = close(file_o);
    
    if(chk == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_o), exit(100);
        
    return (0);
}
