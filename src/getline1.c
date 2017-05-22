/* Author: Ananya Jana
write a program that reads a set of lines and 
prints the lines og length greater than 8    */

#include <stdio.h>
#define  MAXLINE  20

int getline(char s[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;                 /* current line length        */
	int max;                 /* maximum length seen so far */
	char line[MAXLINE];      /* current in put line        */
	char longest[MAXLINE];   /* the longest line seen so far */
	
	max = 0;
	while((len = getline(line, MAXLINE)) > 0)
		if(len > 8)
			printf("%s", line);
	return 0;
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


	
		
			