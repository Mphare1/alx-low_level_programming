#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - -----------==========
 * @b: ======----
 * =========
 * Return: ==============
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int c_1 = 0;
unsigned int g = 0;

if (!b || !*b)
return (0);
	
while (b[g])
{
if (b[g]>49)
return (0);
	
else
if (b[g]==49)
{		
c_1 <<= 1;
c_1 += 1;		
}
	
else
c_1 <<= 1;
g++;
}

return (c_1);

}
