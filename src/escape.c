/* Author: Ananya Jana
1 - 8. write a program to count blanks, tabs and newlines */
#include <stdio.h>

int main()
{
	int c, nb;
	int nt, nl;
	nb = nt = nl = 0;
	while((c = getchar()) != '@'){
		if(c == '\t')
			++nt;
		else if(c == '\n')
			++nl;
		else if(c == ' ')
			++nb;
		else
			;
	}
	printf("the no. of tabs = %d\n", nt);
	printf("the no. of blanks = %d\n", nb);
	printf("the no. of newlines = %d\n", nl); 
}
	