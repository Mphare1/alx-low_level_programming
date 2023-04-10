#include "main.h"
#include <stdio.h>

/**

* binary_to_uint - function that convert a binary number to an unsigned int

* @binary: string to convert.

* Return: converted number or 0
*/
  unsigned int binary_to_uint(const char *binary)
    {
    unsigned int num1 = 0;

    if (!binary || !*binary)
    return (0);

    for (int i = 0; binary[i]; i++)
    {
    if (binary[i] > '1' || binary[i] < '0')
    return (0);
     num1 <<= 1;
 if (binary[i] == '1')
 	num1 = num1 + 1;

}
return (num1);
}
