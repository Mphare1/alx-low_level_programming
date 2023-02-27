#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random passwords for 101-crackme program
 *
 * Return: Always 0
 */
int main(void)
{
    int i, sum, n;
    char c;

    srand(time(0));
    sum = 0;
    i = 0;

    while (sum < 2772 - 122)
    {
        n = rand() % 62;
        if (n < 10)
            c = '0' + n;
        else if (n < 36)
            c = 'A' + n - 10;
        else
            c = 'a' + n - 36;

        sum += c;
        putchar(c);
        i++;
    }

    c = (2772 - sum);
    if (c < 10)
        putchar(c + '0');
    else if (i < 98)
        putchar(c - 10 + 'A');
    else
        putchar(c - 10 + 'a');

    return (0);
}
