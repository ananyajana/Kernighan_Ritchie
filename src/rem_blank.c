/* Author: Ananya Jana
write a program to remove trailing blanks and tabs from
each line of input, and entirely delete blank lines      */

#include <stdio.h>
#define  MAXLINE  80
 

int rem(char s[]);
int getline(char line[], int maxline);


int main()
{
	char line[MAXLINE]; 
	
	while(getline(line, MAXLINE) > 0)
		if(rem(line) > 0)
			printf("%s", line);
	return 0;
}

int rem(char s[])
{
	int i;
	
	i = 0;
	while(s[i] != '\n')
		++i;
	--i;
	
	while( i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	 
	if(i >= 0){
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}

int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	for(i = 0; i < lim - 1 && (c = getchar()) != '@' && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
	