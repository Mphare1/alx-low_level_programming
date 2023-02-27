#include "holberton.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 */
void rev_string(char *s)
{
    int i, j;
    char tmp;

    /* find the length of the string */
    for (i = 0; s[i] != '\0'; i++)
        ;

    /* reverse the string */
    for (i--, j = 0; j < i; j++, i--)
    {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}
