/* Author: Ananya Jana
   write a program to implement a primitive calculator
   which reads one number per line, optionally preceded
   with a sign and adds them up, printing the running sum
   after each input                                     */
   
#include <stdio.h>
#include <ctype.h>
#define MAX 50

double atof(char s[]);
int getline(char s[], int maxline);

/* rudimentary calculator */

int main()
{
	double sum = 0.0;
	char line[MAX];
	
	while(getline(line, MAX) > 0)
		printf("\t%g\n", sum += atof(line));
	
	return 0;	
}

double atof(char s[])
{
	double  val, power;
	int i, sign;
	
	for(i = 0; isspace(s[i]); ++i)
		;
	
	sign = (s[i] == '-') ? -1 : 1;
	
	if(s[i] == '-' || s[i] == '+')
		++i;
	
	for(val = 0.0; isdigit(s[i]); ++i)
		val = val * 10.0 + (s[i] - '0');
	
	if(s[i] == '.')
		++i;
	
	for(power = 1.0;isdigit(s[i]); ++i){
		val = val * 10.0 + (s[i]  - '0');
		power *= 10;
	}
	
	return sign * val / power;
} 

int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	for(i = 0; i < lim - 1 && (c = getchar()) != '@' && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
