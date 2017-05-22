/* write a C program to check for rudimentary syntax errors
like unmatched parentheses, brackets, braces, don' t forget 
about  quotes both single and double escape sequences and 
comments                                               */

#include <stdio.h>

void search(int c);
void in_comment();
void in_quote(int c);

int brace, brack, paren;

int main()
{
	int c;
	extern int brace, brack, paren;		
	
	while((c = getchar()) != '@'){
		if(c == '/'){
			if((c = getchar()) == '*')
				in_comment();
			else
				search(c);
		}
		
		else if(c == '\'' || c == '"')
			in_quote(c);
		else 
			search(c);
			
		if(brace < 0){
			printf("\n unmatched braces");
			brace = 0;
		}
		else if(brack < 0){
			printf("\n unmatched brackets");
			brack = 0;
		}
		else if(paren < 0){
			printf("\n unmatched parentheses");
			paren = 0;
		}
	}	
		if(brace > 0)
			printf("\n unmatched braces");
		if(brack > 0)
			printf("\n unmatched brackets");
		if(paren > 0)
			printf("\n unmatched parentheses");
}

void search(int c)
{
	extern int brace, brack, paren;
	
	if(c == '{')
		++brace;
	else if(c == '[')
		++brack;
	else if(c == '{')
		++paren;
	else if(c == '}')
		--brace;
	else if(c == ']')
		--brack;
	else if(c == ')')
		--paren;
}

void in_comment()
{
	int c, d;
	c = getchar();
	d = getchar();
	while(c != '*' || c != '/'){
		c = d;
		d = getchar();
	}
}

void in_quote(int c)
{
	int d;
	
	while((d = getchar()) != c)
		if(d = '\\')
			getchar();
}
				