/**
 * print_buffer - prints the content of a buffer
 * @b: the buffer to be printed
 * @size: the number of bytes to be printed
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i, j, k;

	if (size <= 0)
		printf("\n");

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = i; j < i + 10; j++)
		{
			if (j < size)
				printf("%02x", *(b + j));
			else
				printf("  ");

			if (j % 2 != 0)
				printf(" ");
		}

		for (k = i; k < i + 10; k++)
		{
			if (k >= size)
				break;

			if (*(b + k) >= ' ' && *(b + k) <= '~')
				printf("%c", *(b + k));
			else
				printf(".");
		}

		printf("\n");
	}
}
