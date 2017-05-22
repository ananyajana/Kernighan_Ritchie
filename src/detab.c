/* Author: Ananya Jana
write a program that replaces  tabs in input with 
proper number of blanks to space to the next tab stop.
assume a fixed set of tabs, say every n columns.should 
n be a variable or symbolic parameter               */

#include <stdio.h>
#define  TS     8


int main()
{
	int nb = 0, c, pos;
	
	for(pos = 1; (c = getchar()) != '@'; ++pos){
		if(c == '\t'){
			nb += TS - (pos - 1) % TS;
			pos += TS - (pos % TS);
		}
		
		else{
			for(; nb > 0; --nb)
				putchar(' ');
			putchar(c);
			
			if(c == '\n')
				pos = 0;
		}
	}
}