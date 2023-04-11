#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * set_bit --------------------
 * @n: -------------------
 * @index: ----------------------------
 * Return: ---------------------------
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int tms = 1;

	if (index > 64)
	return (-1);

tms <<= index;
if (!(*n & tms))
{
	*n |= tms;
	
	return (1);
}
	return (-1);
}
