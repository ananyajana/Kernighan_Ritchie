/* Author: Ananya Jana
write a program to print the only the input lines that contain a certain pattern */

#include <stdio.h>
#define  MAXLINE  50
int getline(char line[], int maxline);
int strindex(char line[], char pattern[]);

int main()
{
	int found = 0;
	char line[MAXLINE];
	char pattern[] = "a";
	while(getline(line, MAXLINE)){
		printf(" %d ", strindex(line, pattern));
		if(strindex(line, pattern) > 0){
			printf("%s", line);
			++found;
		}
	}
	return found;
}

int getline(char s[], int lim)
{
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != '@' && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for(i = 0; s[i]; ++i){
		for(j = i, k = 0; t[k] && t[k] == s[j]; ++j, ++k)
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
		 