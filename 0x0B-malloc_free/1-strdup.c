#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0 succes
 */
char *_strdup(char *str)
{
	int x, y;
	char *array;

	if (str == NULL)
		return (NULL);

	for (y = 0; y <= *str; y++)
	{
	}

	end += 1;
	array = malloc(sizeof(char) * y);

	for (x = 0; x < y; x++)
		array[x] = str[x];

	if (array == NULL)
		return (NULL);
	return (array);
}
