/* Author: Ananya Jana
write a function htoi(s), which converts a string of
hexadecimal digits( includeing an optional 0X or 0x )
into its equivalent integer. the allowable digits are
0 through 9, a through f and A through F.            */

#include <stdio.h>
#include <ctype.h>

int flag = 1;
long htoi(char s[]);

int main()
{
	char s[10];
	long i;
	printf("\n enter the hexadecimal string: ");
	scanf("%s", &s);
	i = htoi(s);
	if(flag)
		printf("\n the hexadecimal number is: %ld", i);
	else
		printf(" ");
}

long htoi(char s[])
{
	int i, j;
	long sum = 0;
	
	for(i = 0; isspace(s[i]; ++i)
		;
	j = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		++i;
	
	for(i = 0; s[i]; ++i){
		if(s[i] == '0' && ( s[i + 1] == 'x' ||  s[i + 1] == 'X'))
			++i;
		
		else if(isdigit(s[i]))
			sum = sum * 16 + (s[i] - '0');
		
		else if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
			sum = sum * 16 + (10 + tolower(s[i]) - 'a');
		
		else {
			printf(" \n not a valid hexadecimal string ");
			flag = 0;
			return 0;
		}
	}
	return sum * j;
}