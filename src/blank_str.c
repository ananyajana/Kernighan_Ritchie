/* Author: Ananya Jana
1 - 9. write a program to copy its input to output 
replacing each string of blanks by a single string */
#include <stdio.h>

int main()
{
	int c, lastc;
	while((c = getchar()) != '@'){
		if(c != '\t' && c != ' ' )
			putchar(c);
		else 
			if(lastc != ' ' && lastc != '\t')
				putchar(' ');
		lastc = c;
	}
}	