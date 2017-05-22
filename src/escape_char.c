s/* 1 - 10. write a program to copy its input to output, replacing each tab by \t, 
each backspace by \b and each backslash by \\                                 */

#include <stdio.h>

int main()
{
	int c;
	
	while((c = getchar()) != '@'){
		if(c == '\b')
			printf("\\b");
		else if(c == '\t')
			printf("\\t");
		else if(c == '\\')
			printf("\\\\");
		else if(c == ' ')
			printf("\\B");
		else
			putchar(c);
	}
}

		