/* Author: Ananya Jana
write a function rightrot(x, n) that returns the 
value of integer x rotated to the right by n positions */

#include <stdio.h>

int bitcount(unsigned x);
unsigned rotate(unsigned x, int n);

int main()
{
	int n;
	unsigned x;
	printf("\n enter a number: ");
	scanf("%u", &x);
	printf("\n enter the no. of bit positions to rotate: ");
	scanf("%d", &n);
	while(n--)
		x = rotate(x, 1);
	printf(" %u ", x);
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

