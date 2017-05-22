/* Author: Ananya Jana
write a function expand(s1, s2) that expands 
shorthand notations like a-z in the string s1
int o equivalent complete list abc...xyz in the
string s2. allow for letters of either case and
digits, and be prepared to handle cases like
a-b-c and a-z0-9 and -a-z. arrange that a leading
or trailing - is taken literally				*/

#include <stdio.h>
#include <ctype.h>

void expand(char s[], char t[]);

int main()
{
	int i, c;
	char s1[10], s2[60];
	
	printf("\n enter the string: ");
	for(i = 0; i < 20 && (c = getchar()) != '@' ; ++i)
		s1[i] = c;
	s1[i] = '\0';
	
	expand(s1, s2);
	printf("\n%s", s2);
}
	
void expand(char s[], char t[])
{
	char c;
	int i, j;
	
	i = j = 0;
	while((c = s[i++]) != '\0')          /* fetch a character from s & increase i */
		if(s[i] == '-' && s[i + 1] > c){
			++i;
			while(c < s[i])              /* expand shorthand                      */
				t[j++] = c++;
		}
		else
			t[j++] = c;
		t[j] = '\0';
}		

	