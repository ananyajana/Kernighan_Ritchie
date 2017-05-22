/* Author: Ananya Jana 
write a program that replaces  tabs in input with 
proper number of blanks to space to the next tab stop.
assume a fixed set of tabs, say every n columns.should 
n be a variable or symbolic parameter               */

#include <stdio.h>
#define  TS     8


int main()
{
	int nb, c, pos;
	pos = 1;
	nb = 0;
		
	while((c = getchar()) != '@'){
		if(c == '\t'){
			nb = TS - (pos - 1) % TS;
			while(nb > 0){
				putchar(' ');
				++pos;
				--nb;
			}
		}
		
		else if(c == '\n'){
			putchar(c);
			pos = 1;
		}
		
		else{
			putchar(c);
			++pos;
		}
	}
}
	