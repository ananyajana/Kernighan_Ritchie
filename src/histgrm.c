/* Author: Ananya Jana
1-13.write a program to print the horizontal histogram
of the lengths of words in its input.                  */
#include <stdio.h>
#define  MAXLEN 10     /* maximum length of a word     */
#define  MAXHIST 15    /* maximum length of a histogram*/

int main()
{
	int flag, max;
	int i, c, len;
	int wl[MAXLEN];
	len = 0;
	max = 0;            /*maximum no of words of a particular length */ 
	flag = 0;
	
	for(i = 0; i < 10; ++i)
		wl[i] = 0;
	
	while((c = getchar()) != '@'){
		if(c != ' ' && c != '\n' && c != '\t'){
			++len;
			flag = 1;
		}
		else{ 
			++wl[len - 1];
			len = 0;
			flag = 0;
		}
	}
	if(flag)
		++wl[len - 1];
	for(i = 0; i < 10; ++i)
		if(wl[i] > max)
			max = wl[i];
	for(i = 0; i < 10; ++i){
		printf("%2d%5d |", i + 1, wl[i]);
		len = wl[i] * 15 / max;
		for( ; len > 0; --len)
			printf("*");
		printf("\n");
	}
}
		
	