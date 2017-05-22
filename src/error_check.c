/* Author: Ananya Jana
write a C program to check for rudimentary syntax errors
like unmatched parentheses, brackets, braces, don' t forget 
about  quotes both single and double escape sequences and 
comments                                               */

#include <stdio.h>

void in_comment();
void in_quote(int c);

int main()
{
	
	int c, x;
	int np, nb, nbk;
	np = nb = nbk = 0;
	while((c = getchar()) != '@'){
		if(c == '\'' || c == '"')
			in_quote(c);
		else if(c == '/')
			if((x = getchar()) == '*')
				in_comment();
		if(c == '(')
			++np;
		else if(c == '{')
			++nb;
		else if(c == '[')
			++nbk;
		else if(c == ')'){
			--np;
			if(np < 0)
				printf("\n unmatched parentheses");
		}
		else if(c == '}'){
			--nb;
			if(nb < 0)
				printf("\n unmatched braces");
		}
		else if(c == ']'){
			--nbk;
			if(nbk < 0)
				printf("\n unmatched brackets");
		}
	}
	if(np > 0)
		printf("\n there are unmatched 	parenthese");
	if(nb > 0)
		printf("\n there are unmatched 	braces");
	if(nbk > 0)
		printf("\n there are unmatched brackets");
}

void in_quote(int c)
{
	int d;
	while((d = getchar()) != c)
		if(d == '\\')
			getchar();	
}

void in_comment()
{
	int c, lastc = 9;
	while(!((c = getchar()) == '/' && lastc == '*'))
		lastc = c;
}		
