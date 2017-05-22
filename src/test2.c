/* Author: Ananya Jana */
#include <stdio.h>

int main()
{
	char c = 'a';
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
				;
		}
		printf("\n");
	}
	i = 2 * c;
	printf(" %d ", i);
}	  
	