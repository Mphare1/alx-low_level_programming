#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * get_bit - ------------
 * @n: -------------
 * @index: ------------------
 * Return: -----------------
 */
int get_bit(unsigned long int n, unsigned int index)
{
int f;
f = ((n >> index) & 1);
if (index > 64)
return (-1); 
return (f);
}
