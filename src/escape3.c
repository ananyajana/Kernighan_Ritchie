/* write a function escape(s, t) that converts characters like 
newline and tab int o visible escape sequences like \n and \t
as it copies string t to s. use a switch. wite a function for 
the other direction as well, converting escape sequences into
real characters                                             */ 
#include <stdio.h>


void back(char* s, char* t);
void escape(char* s, char* t);

int main()
{
	int i, c;
	char s[20], t[30], t1[20];
	
	i = 0;
	while((c = getchar()) != '@' && i < 20)
		s[i++] = c;
	s[i] = '\0';
	escape(s, t);
	printf("%s", t);	
	back(t, t1);
	printf("\n%s", t1);
}

void escape(char* s, char* t)
{
	int i, j;
	
	for(i = 0, j = 0; s[i]; ++i, ++j){
		switch(s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';
				break;
			default:
				t[j] = s[i];
		}
	}
	t[j] = '\0';
} 

void back(char* s, char* t)
{
	int i, j;
	
	for(i = 0, j = 0; s[i]; ++i, ++j){
		switch(s[i]) {
			case '\\':
				switch(s[++i]) {
					case 'n' :
						t[j] = '\n';
						break;
					case 't' :
						t[j] = '\t';
						break;
					default:
						t[j++] = '\\';
						t[j] = s[i];
				}
				break;
			default:
				t[j] = s[i];
		}
	}
	t[j] = s[i];
}


			

		