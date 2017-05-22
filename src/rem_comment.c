/* Author: Ananya Jana
write a C program to remove all comments from a program.
don't forget to handle quoted strings and character constants
properly. c comments don't nest                           */

#include <stdio.h>

void in_comment();
void in_quote(int c);



int main()
{
	
	int c, x;
	while((c = getchar()) != '@'){
		if((c == '\'') || (c == '"'))
			in_quote(c);
		else if(c == '/' ){
			 if((x = getchar()) == '*'){
				 printf("  ");
				 in_comment();
			 }
			 else{
				 putchar(c);
				 putchar(x);
			 }
		}
		else
			putchar(c);
	}
}

void in_quote(int c)
{
	int d;
	while((d = getchar()) != c){
		if(d == '\\'){
			putchar(d);
			putchar(getchar());
		}
	}
	putchar(d);
	putchar(d);	
}

void in_comment()
{
	int c, lastc = 9;
	while(!((c = getchar()) == '/' && lastc == '*')){
		putchar(' ');
		lastc = c;
	}
	putchar(' ');
}		
	
					