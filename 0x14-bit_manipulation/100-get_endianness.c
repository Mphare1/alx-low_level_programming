#include "main.h"

/**
 * get_endianness - =------------------
 *
 * Return: -----======
 */
int get_endianness(void)
{
	
int r= 1;
	
char *g = (char *)&r;

if (*g)
return (1);
  
else
{
	return (0);
}
	
}
