/* deletes all c from the string      */

#include <stdio.h>

void squeeze(char s[], int n);

int main()
{
	char s[50];
	printf("\n enter the string: ");
	scanf("%s", &s);
	squeeze(s, 'c');
	printf("\n%s", s);
}

void squeeze(char s[], int c)
{
	int i, j;
	
	for(i = j = 0; s[i]; ++i)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}