/* Author: Ananya Jana
write a program that replaces strings of blanks by
minimum no. of tabs and blanks to achieve the same spacing
use the same tab stops for detab when eithe a single blank
or tab would suffice to reach a tab stop, which should be 
given preference ?                                        */

#include <stdio.h>
#define   TS    8

int main()
{
	char c;
	int nb, nt, pos;
	nb = nt = 0; 
	
	for(pos = 1; (c = getchar()) != '@'; ++pos){
		if(c == ' '){
			if(pos % TS == 0){
				++nt ;
				nb = 0;
			}
			else
				++nb;
		}
		
		else if(c == '\t'){
			++nt;
			nb = 0;
			pos = pos + (TS - (pos % TS));
		}
				
		else{

			for(; nt > 0; --nt)
				putchar('\t');

			for(; nb > 0; --nb)
				putchar(' ');

			if(c == '\n')
				pos = 0;
			putchar(c);
		}
	}
}
			
	