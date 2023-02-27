#include <stdio.h>
#include <string.h>

/**
 * puts2 - prints every other character of a string, starting with the first
 * character, followed by a new line
 * @str: input string
 */
void puts2(char *str)
{
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i += 2) {
        putchar(str[i]);
    }

    putchar('\n');
}
