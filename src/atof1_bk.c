/* Author: Ananya Jana
expand atof to handle scientific notation of the form
	123.45e-6
	where a floating point number may be follwed by e or E
	and an optionally signed exponent                   */

#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double                      */

double atof1(char s[]);

int main()
{
	int j;
	double i;
	char c, str[10];	
	
	for(j = 0; (c = getchar()) != '@'; ++j)
		str[j] = c;
	
	str[j] = '\0';
	
	i = atof1(str);
	printf("\n%lf\n", i);
}

double atof1(char s[])
{
	double val, power;
	int exp, i, sign;
	
	for(i = 0; isspace(s[i]); ++i)
		;
		
	sign = (s[i] == '-') ? -1 : 1;
	
	if(s[i] == '-' || s[i] == '+')
		++i;
		
	for(val = 0.0; isdigit(s[i]); ++i)
		val = val * 10.0 + (s[i] - '0');
		
	if(s[i] == '.')
		++i;
		
	for(power = 1.0; isdigit(s[i]); ++i){
		val = val * 10.0 + (s[i] - '0');
		power *= 10.0;
	}
	
	val = sign * val / power;
	
	if(s[i] == e' || s[i] == 'E'){
		sign = (s[++i] == '-') ? -1 : 1;
		
		if(s[i] == '+' || s[i] == '-')
			++i;
			
		for(exp = 0; isdigit(s[i]); ++i)
			exp = exp * 10 + (s[i] - '0');
			
		if(sign == 1)
			while(exp-- > 0)
				val *= 10;
		else
			while(exp-- > 0)
				val /= 10;
	}
	
	return val;
}
