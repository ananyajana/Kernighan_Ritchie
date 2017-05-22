/* Author: Ananya Jana */

#include <stdio.h>

int main()
{
	int i, j, s[6];
	for(i = 0; i < 6; ++i){
		s[i] = i + 1;
		printf("%2d", s[i]);
	}
	printf("\n");
	for(j = 1; j < 7; ++j){
		for(i = 0; i < 6; ++i){
			if(s[i] >= j)
				printf("%2c", '*');
			else
				printf("%2c", ' ');
		}
		printf("\n");
	}
}	  
	