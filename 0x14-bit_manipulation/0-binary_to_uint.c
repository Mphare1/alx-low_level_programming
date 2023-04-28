
#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned int
 * @b: Binary string to convert
 *
 * Return: The converted unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num2, i;

	if (!b || !*b)
		return (0);
/**
 * 
 *
 *
 * 
 */
	num2 = i = 0;
	while (b[i])
	{
		if (b[i] > 49)
			return (0);
		else if (b[i] == 49)
		{
			num2 <<= 1;
			num2 += 1;
		}
		else
			num2 <<= 1;
		i++;
	}
	return (num2);
}
