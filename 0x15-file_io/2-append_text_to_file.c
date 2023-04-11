#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * append_text_to_file - *******************
 * @filename: name of file*********
 * @text_content: text********
 *
 * Return: *****************
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fil_des = 0;
    int   err_c = 0;
    int   x = 0;


    if (!filename)
        return (-1);
    else if (!text_content || !text_content[0])
        return (1);
    fil_des = open(filename, O_WRONLY | O_APPEND);
    if (fil_des < 0)
        return (-1);

    for (;; text_content[x]; x++)
        continue;
    
    err_c = write(fil_des, text_content, x);
    if (err_c < 0)
        return (-1);
    
    close(fil_des);
    return (1);
}
