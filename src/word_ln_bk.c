/* Author: Ananya Jana
1-12. write a program that prints its input one word per line */

#include <stdio.h>
#define  OUT    0
#define  IN     1
     
int main()
{
	int c;
	int state;
	state = OUT;
	while((c = getchar()) != '@'){
		if(c == ' ' || c == '\t' || c == '\n'){     /*outside a word       */
			if(state == IN)
				putchar('\n');
			state = OUT;
		}
		else if(state == OUT){                      /* beginning of a word  */
			putchar(c);
			state = IN;
		}
		else                                        /* inside a word        */
			putchar(c);
	}
}
		