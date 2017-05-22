/* Author: Ananya Jana
write a function getbits(x, p, n) that returns the
(right adjusted) n bit field of x that begins at position 
p. we assume that bit position zero is at the right end
and n and p are sensible positive values              */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
	unsigned x, i;
	printf("\n enter a number: ");
	scanf("%u", &x);
	i = getbits(x, 3, 4);
	printf(" %u ", i);
}	
	
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}