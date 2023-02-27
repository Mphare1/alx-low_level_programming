/**
 * _puts - Prints a string to stdout
 * @str: Pointer to the first character of the string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}

	putchar('\n');
}
