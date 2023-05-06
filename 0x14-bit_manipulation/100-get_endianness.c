#include <stdio.h>
#include "main.h"

/**
 * get_endianness - .........
 * Return: 0.....
 */
 
int get_endianness(void)
{
    unsigned int mask = 1;
    
    char *chec = (char *)&mask;
    
    if(*chec)
     
        return (1);
        
    return (0);
}
