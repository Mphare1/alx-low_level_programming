#include "main.h"
#include <stdio.h>

/**

* binary_to_uint - function that convert a binary number to an unsigned int

* @binary: string to convert.

* Return: converted number or 0
*/
  unsigned int binary_to_uint(const char *b)
    {
    unsigned int num1 = 0;

    if (!b || !*b)
    return (0);

    for (int i = 0; b[i]; i++)
    {
    if (b[i] > '1' || b[i] < '0')
    return (0);
     num1 <<= 1;
 if (b[i] == '1')
 	num1 = num1 + 1;

}
return (num1);
}
