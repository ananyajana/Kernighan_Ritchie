/* Author: Ananya Jana
write a function bitcount(x) to count the 
no. of bits in a number                   */ 

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	int i;
	unsigned x;
	printf("\n enter a number: ");
	scanf("%u", &x);
	i = bitcount(x);
	printf("the no. of bits in x  = %d ", i);
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

/* another version of bitcount is given below
	
int bitcount(unsigned x)            
{									
	int n= 0;						
	while(x && 01){					 while(x || 0){				 
		++n;						 	++n;
		x = x >> 1;						x = x >> 1;				
}								     }
	return n;
}

*/