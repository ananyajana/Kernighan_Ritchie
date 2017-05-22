/* Author: Ananya Jana */
#include <stdio.h>

int power(int m, int n);

int main()
{
	int i;
	printf("%d  %d\n", power(2,7), power(-3, 3));
}

int power(int base, int n)
{
	int  p, i;
	p = 1;
	for(i = 1; i <= n; ++i)
		p  = p * base;
	return p;
}