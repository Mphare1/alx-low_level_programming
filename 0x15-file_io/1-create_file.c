#include "main.h"

/**
 * create_file - Create a file.
 * @filename: Name of the file.
 * @text_content: content to be written in the file.
 * Return: 1 on success else -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int open_f, start_write;
    
    /*Check content file*/
    if(!filename)
        return (-1);
    open_f = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
    
    if(open_f == -1)
        return (-1);
        
    if(!text_content)
        return (1);
        
        
    start_write = write(open_f, text_content, strlen(text_content));
    close(open_f);
    if(start_write == -1)
    {
        close(open_f);
        
        return (-1);
    }
    
    return (1);
    
}
