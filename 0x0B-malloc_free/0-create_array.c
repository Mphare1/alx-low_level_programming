/**
 * create_array - creates an array of chars, and initializes it with a specific char.
 * @size: the size of the array to create
 * @c: the char to initialize the array with
 *
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;

    /* check for invalid input */
	if (size == 0)
	return (NULL);

	/* allocate memory for the array */
	array = malloc(size * sizeof(char));
	if (array == NULL)
	return (NULL);

	/* initialize the array with the specified character */
	for (unsigned int i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
