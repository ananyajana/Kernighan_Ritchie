/* Author: Ananya Jana
write a function strindex(s, t) which returns the position of the 
rightmost occurrence of t in s or -1 if there is none             */

#include <stdio.h>
#define  MAX  50
int strindex(char line[], char pattern[]);

int main()
{
	int l = 0, i, c;
	char line[MAX];
	char pattern[] = "ab";
	for(i = 0; (c = getchar()) != '@' && i < MAX - 1 && c != '\n'; ++i)
		line[i] = c;
	if(c == '\n')
		line[i++] = c;
	line[i] = '\0';
	l = strindex(line, pattern);
		if(l >= 0)
			printf("the rightmost position of the pattern is %d\n", l);
		else
			printf("no occurrence of the pattern\n");
}


int strindex(char s[], char t[])
{
	int i, j, k;
	int found = -1;
	
	for(i = 0; s[i]; ++i){
		for(j = i, k = 0;s[j] == t[k] && t[k]; ++k, ++j)
			;
		if(k > 0 && t[k] == '\0'){
			found = i;
		}
	}
	if(found >= 0)
		return found;
	else
		return -1;
}
		 