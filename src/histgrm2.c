/* Author: Ananya Jana
1-13.write a program to print the vertical
histogram of the lengths of words in its input.        */
#include <stdio.h>
#define  MAXLEN 10     /* maximum length of a word     */
#define  MAXHIST 15    /* maximum length of a histogram*/

int main()
{
	int flag, max;
	int i, c, len, l, k[11];
	int wl[MAXLEN + 1], j;
	len = 0;
	max = 0;            /*maximum no of words of a particular length */ 
	flag = 0;
	
	for(i = 1; i <= 10; ++i)
		wl[i] = 0;
	
	while((c = getchar()) != '@'){
		if(c != ' ' && c != '\n' && c != '\t'){
			++len;
			flag = 1;
		} 
		else{ 
			++wl[len];
			len = 0;
			flag = 0;
		}
	}
	if(flag)
		++wl[len];
	for(i = 1; i <= 10; ++i)
		if(wl[i] > max)
			max = wl[i];

	for(i = 1; i <= 10; ++i)
		printf("%3d", wl[i]);
	printf("\n");
	
	for(i = 1; i <= 10; ++i)
		printf("%3d", i);
	printf("\n");

	for(i   = 0 ; i < 31; ++i)
		printf("%c", '-');
	printf("\n");
	
	for(i = 1; i <= 10; ++i){
		k[i] = wl[i] * MAXHIST / max; 
	}
	
	for(i = 1; i < 16; ++i){
		for(j = 1; j <= 10; ++j) {
			if(k[j] >= i)	
				printf("%3c", '*');
			else
				printf("%3c", ' ');
		}
		printf("\n");
    }
}