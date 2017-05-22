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
	char s1[10], s2[50];
	
	printf("\n enter the string: ");
	for(i = 0; i < 10 && (c = getchar()) != '@' ; ++i)
		s1[i] = c;
	s1[i] = '\0';
	
	expand(s1, s2);
	printf("\n%s", s2);
}
	
void expand(char s[], char t[])
{
	char c;
	int flag = 0;
	int i, j, k;
	
	for(i = 0, j = 0; s[i]; ++i, ++j){
		if(s[i] == '-'){
			
			if(tolower(s[i - 1]) >= 'a' && tolower(s[i - 1]) <= 'z')
				if(tolower(s[i + 1]) >= 'a' && tolower(s[i + 1]) <= 'z') 
					if( s[i + 1] - s[i - 1] <= 25)
						flag = 1;
			
			if(isdigit(s[i - 1]) && isdigit(s[i + 1]))
				if(s[i - 1] < s[i + 1]) 
					flag = 1;				
				
			else
				flag = 0;
		}
		if(flag){
			j = i;
			c = s[i];
			c++;
			while(c != s[i + 2])
				t[j++] = c++;
			t[j] = c;
			i += 1;
			flag = 0;
		}
		else
			t[j] = s[i];
	}
	t[j] = '\0';
}
	