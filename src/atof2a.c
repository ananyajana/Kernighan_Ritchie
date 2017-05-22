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
	double  val, power = 1.0;
	int i, sign, exp;
	
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
	val = sign * val / power;

	if(s[i] == 'e' || s[i] == 'E'){
		sign = (s[++i] == '-')? -1 : 1 ;
		
		if(s[i] == '-' || s[i] == '+')
			++i;
		n = s[i];
		
		for(exp = 0; isdigit(s[i]); ++i)
			exp = exp * 10 + (s[i] - '0');
		
		if(sign == 1)
			while(exp-- > 0)			
				val *= exp;
		else
			while(exp-- > 0)
				val /= exp;			
	}
	
	return val; 
} 
