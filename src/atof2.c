/* Author: Ananya Jana */
#include <stdio.h>
#include <ctype.h>

double atof2(char s[]);

int main()
{
	int j;
	double i;
	char c, str[10];	
	
	for(j = 0; (c = getchar()) != '@'; ++j)
		str[j] = c;
	
	str[j] = '\0';
	
	i = atof2(str);
	printf("\n%lf\n", i);
}

double atof2(char s[])
{
	double  val, power = 1.0, exp;
	int i, sign, sign1;
	char n;
	
	for(i = 0; isspace(s[i]); ++i)
		;
	
	sign = (s[i] == '-') ? -1 : 1;
	
	if(s[i] == '-' || s[i] == '+')
		++i;
	
	for(val = 0.0; isdigit(s[i]); ++i)
		val = val * 10.0 + (s[i] - '0');
	
	if(s[i] == '.'){
		++i;
		for( ;isdigit(s[i]); ++i){
			val = val * 10.0 + (s[i]  - '0');
			power *= 10;
		}
	}
	
	if(s[i] == 'e' || s[i] == 'E'){
		++i;
		sign1 = (s[i] == '-')? -1 : 1 ;
		if(s[i] == '-' || s[i] == '+')
			++i;
		n = s[i];
		for(exp = 1.0; n > '0'; --n)
			exp = exp * 10.0;
		if(sign1 == 1)
			power /= exp;
		else
			power *= exp;			
	}
	
	return sign * val / power;
} 
