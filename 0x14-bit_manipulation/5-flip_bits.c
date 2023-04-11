/**
 * flip_bits - *********
 * ************
 * @n: .********.
 * @m: ..***********
 *
 * Return:************************
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int bits2 = 0;

while (n || m)
{
  
	bits2 += (n & 1) != (m & 1); /****/
  
	n >>= 1;
	m >>= 1;
  
}

return (bits2);
}
