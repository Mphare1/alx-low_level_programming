#include <unistd.h>

/**
 * main - the chars/ arrays
 *
 * Return: Always 1 (Error)
 */
int main(void)
{
	char *cr = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	int length = 0;

	while (cr[length] != '\0')
		length++;

	write(2, cr, length);

	return (1);
}
