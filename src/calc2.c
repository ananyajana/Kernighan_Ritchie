#include <stdio.h>
#include <stdlib.h>

#define MAXOP 30
#define NUMBER '0'

double pop(void);
void push(double);
int getop(char []);

/* reverse polish calculator                      */

int main()
{
	int type;
	double op2;
	char s [MAXOP];
	
	while((type = getop(s)) != '@'){
		switch(type){
			
			case NUMBER :
				push(atof1(s));
				break;
				
			case '+' :
				push(pop() + pop());
				break;
				
			case '*' :
				push(pop() * pop());
				break;
			case '-' :
				op2 = pop();
				push(pop() - op2);
				break;
			
			case '/' :
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("\n zero divisor");
				break;
			
			case '\n' :
				printf("\t%.8g\n", pop());
				break;
				
			default :
				printf("\n unknown command");
		}
	}
	return 0;
}
	