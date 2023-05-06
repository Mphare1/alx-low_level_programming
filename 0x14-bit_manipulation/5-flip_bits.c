#include <stdio.h>
#include <conio.h>

/**
 * flip_bits -...
 * @n: .......
 * @m: ......
 * Return: ......
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int bts = 0;
unsigned long int to_xor = n ^ m;
    
while(to_xor)
{
bts += to_xor & 1;
to_xor >>= 1;
}
    
return (bts);
}
