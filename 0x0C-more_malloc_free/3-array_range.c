#include <stdlib.h>

/**
 * array_range - create an array of integers
 * @min: the minimum value (inclusive)
 * @max: the maximum value (inclusive)
 *
 * Return: On success, return a pointer to the newly created array.
 *         On failure, return NULL.
 */
int *array_range(int min, int max)
{
	int *array, i, j;

	if (min > max)
		return (NULL);

	array = malloc(sizeof(int) * (max - min + 1));
	if (!array)
		return (NULL);

	for (i = min, j = 0; i <= max; i++, j++)
		array[j] = i;

	return (array);
}
