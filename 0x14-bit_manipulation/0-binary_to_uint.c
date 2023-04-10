#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - function that does conversion
 * @b: string to convert.
 *
 * Return: number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (!b|| !*b)
		return (0);

	for (int i = 0; b[i]; i++)
	{
		if (b[i] > '1' || b[i] < '0')
			return (0);

		num <<= 1;
		if (b[i] == '1')
			num += 1;
	}

	return (num);
}
