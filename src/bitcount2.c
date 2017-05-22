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
	int i = 0;
	while(x){
		x = x & (x - 1);
		++i;
	} 
	return i;
}