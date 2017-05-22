
#include <stdio.h>

int power(int m, int n);

int main()
{
	int i;
	printf("%d  %d\n", power(2,7), power(-3, 3));
}

int power(int base, int n)
{
	int  p;
	for(p = 1; n > 0; --n)
		p  = p * base;
	return p;
}