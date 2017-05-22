/* write a function rightrot(x, n) that returns the 
value of integer x rotated to the right by n positions */

#include <stdio.h>

unsigned rotate(unsigned x, int n);

int main()
{
	int n;
	unsigned x, i;
	printf("\n enter a number: ");
	scanf("%u", &x);
	printf("\n enter the no. of bit positions to rotate: ");
	scanf("%d", &n);
	i = rotate(x, n);
	printf("\n now the number is: %d", i);
}

unsigned rotate(int x, int n)
{
	int wordlength(void);
	int rbit;
	
	while(n--){
		rbit = (x & 1) << (wordlength - 1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

int wordlength()
{
	int i;
	unsigned v = (unsigned) ~0;
	for(i = 1; (v = v >> 1); ++i)
		;
	return i;
}
