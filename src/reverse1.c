/* write a function reverse(s) that reverses the 
character string s. use it to write a program 
that reverses its input line one at a time     */

#include <stdio.h>
#include <string.h>
#define MAXLINE 10


int getline(char s[], int maxline);
void reverse(char line[]);

int main()
{
	int len;
	int max; 				 /* maximum length seen so far */
	char line[MAXLINE];      /* current input line         */
	
	len = 0;
	max = 0;
	while((len = getline(line, MAXLINE)) > 0){
		if(len > 0){
			reverse(line);
			printf("%s\n", line);
		}
		else
			printf("can't be reversed");
	}
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

void reverse(char s[])
{
	int i, j, c;
	
	for(i = 0, j = strlen(s) - 1; i < j; ++i, --j){
		c  = s[i];
		s[i] = s[j];
		s[j] = c;
	}
} 


	