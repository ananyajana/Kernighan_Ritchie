/* Author: Ananya Jana
write a program that replaces strings of blanks by
minimum no. of tabs and blanks to achieve the same spacing
use the same tab stops for detab when eithe a single blank
or tab would suffice to reach a tab stop, which should be 
given preference ?                                        */

#include <stdio.h>
#define   TS    8        /* tab increment size */


int main()
{
	int c, nb, nt, pos;
	
	nb = 0;
	nt = 0;
	
	for(pos = 1; (c = getchar()) != '@'; ++pos){
		if(c == ' '){
			if(pos % TS == 0){
				++nt;
				nb = 0;
			}
			else
				++nb;
		}
		 
		else{
			for(; nt > 0; --nt)
				putchar('\t');
			if(c == '\t')
				nb = 0;
			else
				for(; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if(c =='\n')
				pos = 0;
			else if(c == '\t')
				pos = pos + (TS - (pos - 1)%TS) - 1;
		}
	}
}
	