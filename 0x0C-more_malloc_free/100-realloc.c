/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 *         NULL if new_size == 0 and ptr != NULL
 *         ptr if new_size == old_size
 *         NULL if malloc fails or if ptr is NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *orig_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);

		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	orig_ptr = ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = orig_ptr[i];

	free(ptr);

	return (new_ptr);
}
