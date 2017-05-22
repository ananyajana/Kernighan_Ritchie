/* write a program to concatenate two strings */

#include <stdio.h>

void xstrcat(char s[], char t[]);

int main()
{	
	char s[30], t[10];
	printf("\n enter the first string: ");
	scanf("%s", &s);
	printf("\n enter the second string: ");
	scanf("%s", &t);
	xstrcat(s, t);
	printf("\n %s", s);
}

void xstrcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while(s[i] != '\0')
		++i;
	while((s[i++] = t[j++]) != '\0')
		;
}

		 