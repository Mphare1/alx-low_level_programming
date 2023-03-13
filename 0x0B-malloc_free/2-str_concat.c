#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * str_concat - get ends of input and add together for size
 * @s1: input one to concat
 * @s2: input two to concat
 * Return: concat of s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	int x, y, i = 0;
	char *array;

	if (s1 == NULL || s2 == NULL)
		s1 = s2 = "";

	for (x = 0; x <= *s1; x++)
	{
	}

	for (y = 0; y <= *s2; y++)
	{
	}

	array = malloc(sizeof(char) * (x + y + 1));

	if (array == NULL)
		return (NULL);

	while (*s1)
	{
		array[i] = *s1;
		i++;
		s1++;
	}

	while (*s2)
	{
		array[i] = *s2;
		i++;
		s2++;
	}
	return (array);
}
