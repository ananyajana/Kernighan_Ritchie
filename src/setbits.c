/* Author: Ananya Jana
write a function setbits(x, p, n, y) that returns x 
with the n bits that begin at position p set to the 
rightmost n bits of y                               */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	unsigned x, i, y;
	printf("\n enter two  numbers: ");
	scanf("%u%u", &x, &y);
	i = setbits(x, 1, 2, y);
	printf(" %u ", i);
}	
	
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0 << n) <<  (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}