/* Author: Ananya Jana
1 - 2. experiment to find out what happens when printf's argument contains
\c where c is some character not listed above                            	

1 - 6. verify that the expression getchar() != EOf is 0 or 1;

1 - 7.print the value of EOF                                                 */

#include <stdio.h>

int main()
{
	int c, i = 12;	
	float f = 5;
	printf("%09.0f %5d\n", f, i);
	printf("rupa is a good\b\b\b\bgirl ");
	printf("%d %c\n", EOF, EOF);
	while( c = getchar() != '@')
		printf("\n%d", c);	
	printf("\n%d", c);
}