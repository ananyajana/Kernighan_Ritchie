#include <stdio.h>

char* itoa(int val, int base);

int main()
{
	int n;
	char* s;
	
	printf("\n enter the value of n: ");
	scanf("%d", &n);
	s = itoa(n, 16);
	printf("%s\n", s);
}


char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];

	
}
