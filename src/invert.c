/* write a function invert(x, p, n) that returns x 
with the n bits that begin at position p inverted */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
	unsigned x, i;
	printf("\n enter a number: ");
	scanf("%u", &x);
	i = invert(x, 1, 2);
	printf(" %u ", i);
}	
	
unsigned invert(unsigned x, int p, int n)
{
	return (x ^ (~(~0 << n) <<  (p + 1 - n)));
}