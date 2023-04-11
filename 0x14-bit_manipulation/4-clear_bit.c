#include "main.h"

/**
 * clear_bit -----------------
 * @n: ----------------
 * @index: -----------------
 * Return: ************************
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long int tms = 1;

if (index > 63)
	return (-1);

tms <<= index;
if (*n & mask)
{
tms = ~tms;    
*n &= tms;    
return (1);
    
}  
return (-1);
}
