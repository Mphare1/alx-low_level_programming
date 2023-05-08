#include "main.h"
/**
  * append_text_to_file - Appends text at the end
  * @filename: Name of the file.
  * @text_content: ...
  * Return: 1 on success or -1 on failure
  */
int append_text_to_file(const char *filename, char *text_content)
{
    int open_f, stats, counter = 0;
    
    if(filename == NULL)
        return (-1);
    if(text_content == NULL)
        return (1);
        
    open_f = open(filename, O_APPEND | O_WRONLY);
    if(open_f == -1)  /*If it fails*/
        return (-1);
        
    for(; text_content[counter] != '\0'; counter++)
        ;
    stats = write(open_f, text_content, counter);
    
    if(stats == -1)
        return (-1);
        
    close(open_f);
    
    return (1);
}
