/* Author: Ananya Jana
1 - 9. write a program to copy its input to output 
replacing each string of blanks by a single string */
#include <stdio.h>

int main()
{
	int c;
	int flag;
	flag = 0;
	while((c = getchar()) != '@'){
		if(c != ' ' && c != '\t' ){
			putchar(c);
			flag = 0;
		}
		else
			if(flag)
				;
			else{
				putchar(' ');
				flag = 1;
			}
	}
}