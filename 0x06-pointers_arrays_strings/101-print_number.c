
/**
 * print_number - Prints an integer
 *
 * @n: Integer to print
 */
void print_number(int n)
{
    int divisor = 1;
    int i, j, digit;

    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }

    i = n;
    while (i > 9)
    {
        i /= 10;
        divisor *= 10;
    }

    for ( ; divisor >= 1; divisor /= 10)
    {
        digit = (n / divisor) % 10;
        _putchar(digit + '0');
    }
}
