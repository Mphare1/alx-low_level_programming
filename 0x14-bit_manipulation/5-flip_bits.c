#include <stdio.h>
#include <conio.h>

/**
 * flip_bits - returns the number of bits you would need to flip
 *             to get from one number to another.
 * @n: number to be flipped
 * @m: number to filp n to
 * Return: no. of bits to be flipped
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
