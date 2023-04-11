#include "main.h"
#include <stdio.h>

/**
 * print_binary -777777777777777
 * @n: 8888888888888888888
 * -----------------
 */
void print_binary(unsigned long int n)
{
if (n>1)
print_binary(n>>1);
_putchar((n & 1)+ '0');
	
}
