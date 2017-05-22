/* write a C program to remove all comments from a program.
don't forget to handle quoted strings and character constants
properly. c comments don't nest                           */

#include <stdio.h>

void rcomment(int c);
void in_comment();
void in_quote(int c);
		
int main()
{
	int c;
	
	while((c = getchar()) != '@')
		rcomment(c);
	return 0;
}

void rcomment(int c)
{
	int d;
	
	if(c == '/'){
		if((d = getchar()) == '*')
			in_comment();
		
		else if(d == '/'){
			putchar(c);
			putchar(d);
		}
		
		else {
			putchar(c);
			putchar(d);
		}
	}
	
	else if( c == '\'' || c == '*')
		in_quote(c);
	else
		putchar(c);
}

void in_comment()
{
	int c, d;
	c = getchar();
	d = getchar();
	
	while(c != '*' || d != '/'){
		c = d;
		d = getchar();
	}
}

void in_quote(int c)
{
	int d;
	putchar(c);
	while((d = getchar()) != c){
		putchar(d);
		if(d == '\\')
			putchar(getchar());
	}
	putchar(d);
}
	