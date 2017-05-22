/* Author: Ananya Jana
write a function rightrot(x, n) that returns the 
value of integer x rotated to the right by n positions */

#include <stdio.h>

int bitcount(unsigned x);
unsigned rotate(unsigned x, int n);

int main()
{
	unsigned x, i;
	printf("\n enter a number: ");
	scanf("%u", &x);
	i = rotate(x, 2);
	printf(" %u ", i);
}	
	
unsigned rotate(unsigned x, int n)
{
	int i;
	i = bitcount(x);
	return ((x & ~(~0 << n)) << (i - n)) | (x >> n);
}

int bitcount(unsigned x)
{
	int n = 0;
	while(x | 00){
		++n;
		x = x >> 1;
	} 
	return n;
}

