/* Author: Ananya Jana
write  a function itob(n, s, b) that converts the integer n into a base 
b character representation in string s. in particular itob(n, s, 16)
formats s as a hexadecimal integer in s                                 */

#include <stdio.h>
#include <string.h>

void reverse(char* s);
void itoa(int n, char* s);

int main()
{
	int n, b;
	char s[10];
	printf("enter the decimal no. :");
	scanf("%d", &n);
	itoa(n, s);
	printf("the character representation of the no.: %s", s);
}
 
void itoa(int n, char* s)
{
	int i;
	int sign;
	
	sign = n;
	if(n < 0)
		n = -n;
	i = 0;
	while(n){
		s[i++] = n % 10 + '0';
		n = n / 10;
	}
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	printf("\n%s", s);
	reverse(s);
}

void reverse(char s[])
{
	int i, j, c;
	
	for(i = 0, j = strlen(s) - 1; i < j; ++i, --j){
		c  = s[i];
		s[i] = s[j];
		s[j] = c;
	}
} 