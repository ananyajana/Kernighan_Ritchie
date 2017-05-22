/* write a program to implement a primitive calculator
   which reads one number per line, optionally preceded
   with a sign and adds them up, printing the running sum
   after each input                                     */
   
#include <stdio.h>
#include <ctype.h>
#define MAX 50

/* rudimentary calculator */

int main()
{
	double sum = 0.0, atof1(char s[]);
	char line[MAX], getl(char s[], int max);
	
	while(getl(line, MAX) > 0)
		printf("\t%g\n", sum += atof1(line));
	
	return 0;	
}
