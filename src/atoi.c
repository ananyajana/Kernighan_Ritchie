/* write a function atoi that converts a string 
s to integer                                 */

#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main()
{
	int i, c;
	char str[10];
	
	i = 0;
	
	while(i < 10 && c != '@'){
		c = getchar();
		str[i++] = c;
	}
	str[i] = '\0';
	i = atoi(str);
	printf("\n%d\n", i);
}

int atoi(char s[])
{
	int i, n, sign;
	
	for(i = 0; isspace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		++i;
	for(n = 0; isdigit(s[i]); ++i)
		n = n * 10 + (s[i] - '0');
	return n * sign;
} 


		   