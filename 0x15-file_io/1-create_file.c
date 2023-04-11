#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * create_file - ....... create a file
 * @filename: ************
 * @text_content: ******** add to the file.
 *
 * Return: 1 **** or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int err_c =0, x=0, file_des=0;
	if (!filename)
	{
		
	return (-1);
		
	}
	file_des = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	
	if (file_des < 0)
	{
		
	return (-1);
	
	}
	while (text_content && text_content[x])
	x++;

	err_c = write(file_des, text_content, x);
	
	if (err_c < 0)
	{
		
	return (-1);
		
	}
	
	close(file_des);
	
	return (1);
}
