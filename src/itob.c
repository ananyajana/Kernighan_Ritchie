/* write  a function itob(n, s, b) that converts the integer n into a base 
b character representation in string s. in particular itob(n, s, 16)
formats s as a hexadecimal integer in s                                 */

#include <stdio.h>

void itob(int n, char* s, int b);

int main()
{
	int n, b;
	char s[10];
	printf("enter the decimal no. and the base :");
	scanf("%d%d", &n, &b);
	itob(n, s, b);
	printf("the character representation of the no.: %s", s);
}
 
void itob(int n, char* s, int b)
{
	int m[10], i;
	i = 0;
	while(n){
		m[i++] = n % b + '0';
		n = n / b;
	}
	--i;
	for( ; i > 0; --i)
		printf("%d", m[i]);
}
	