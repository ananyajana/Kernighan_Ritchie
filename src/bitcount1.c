/* write a function bitcount(x) to count the 
no. of 1 bits in a number                 */ 

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	int i;
	unsigned x;
	printf("\n enter a number: ");
	scanf("%u", &x);
	i = bitcount(x);
	printf("the no. of 1 bits in x  = %d ", i);
}	
	
int bitcount(unsigned x)
{
	int n = 0, b = 0;
	
	for( ; x; x >>= 1)
		if(x & 01)
			++b;
	return b;
}