/* 1-13.write a program to print the horizontal histogram
of the lengths of words in its input.                  */
#include <stdio.h>
#define  MAXHIST 15    /* maximum length of a histogram*/

int main()
{
	int flag, max;
	int i, c, len;
	int wl[128];
	len = 0;
	max = 0;            /*maximum no of words of a particular length */ 
	flag = 0;
	
	for(i = 33; i < 127; ++i)
		wl[i] = 0;
	
	while((c = getchar()) != '@')
		++wl[c];
	for(i = 33; i < 127; ++i)
		if(wl[i] > max)
			max = wl[i];
	for(i = 33; i < 127; ++i){
		printf("%5c%2d |", i, wl[i]);
		len = wl[i] * 15 / max;
		for( ; len > 0; --len)
			printf("*");
		printf("\n");
	}
}
		
	