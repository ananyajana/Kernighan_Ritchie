/* Author: Ananya Jana
write a program that can count the occurrences
of each digit, white spaces and other character*/

#include <stdio.h>

int main()
{
	int c, i, nwhite, nother, ndigit[10];
	nwhite = nother = 0;
	for(i = 0; i < 10; ++i)
		ndigit[i] = 0;
	while((c = getchar()) != '@'){
		switch(c){
			case '0' : case '1' : case '2' : case '3' : case '4' : 
			case '5' : case '6' : case '7' : case '8' : case '9' :
				++ndigit[c - '0'];
				break;
			case '\n' : case '\t' : case ' ' :
				++nwhite ;
				break;
			default :
				++nother;
				break;
		}
	}
	
	printf("\n the count  is given below ");
	
	for(i = 0; i < 10; ++i)
		printf("%d %d\n", i, ndigit[i]);
	
	printf("\n white spaces = %d, other chatacters = %d", nwhite, nother);
	
	return 0;
}