/* write a function expand(s1, s2) that expands 
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
	int i, j, k;
	
	for(i = 0, j = 0; s[i]; ++i, ++j){
		if(s[i + 1] == '-'){
			if(isdigit(s[i]) && isdigit(s[i + 2])){
				if(s[i] < s[i + 2]) {
					j = i;
					c = s[i];
					while(c != s[i + 2])
						t[j++] = c++;
					t[j] = c;
					i += 2;
				}
				else{
					k = i;
					while(k != i + 2)
						t[j++] = s[k++];
					t[j] = s[k];
					i = k;
				}
			}
			else if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'){
				if(tolower(s[i + 2]) >= 'a' && tolower(s[i+ 2]) <= 'z' && s[i + 2] - s[i] <= 25){
					j = i;
					c = s[i];
					while(c != s[i + 2])
						t[j++] = c++;
					t[j] = c;
					i += 2;
				}
				else{
					k = i;
					while(k != i + 2)
						t[j++] = s[k++];
					t[j] = s[k];
					i = k;
				}
			}
			else
				t[j] = s[i];
		}
		else
			t[j] = s[i];
	}
	t[j] = '\0';
} 
					
				
	