/* Author: Ananya Jana
write a function atof that converts a
string s to integer                   */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	int j;
	double i;
	char c, str[10];	
	
	for(j = 0; (c = getchar()) != '@'; ++j)
		   str[j] = c;
	
	str[j] = '\0';
	
	i = atof(str);
	printf("\n%lf\n", i);
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


		   