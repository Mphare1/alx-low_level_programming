#include <stdio.h>
#include "main.h"

/**
 * clear_bit - ....
 * @n: ........
 * @index: .........
 * Return: ....
 */
 
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned int a = 1 << index;
    
if(index > 63)
return (-1);
        
        
if(*n & a)
*n ^= a;
        
return (1);
    
}
