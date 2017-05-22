/* Author: Ananya Jana */

#include <stdio.h>
#define MAXVAL 100   /* maximum lengthe of val stack  */ 

int sp = 0;          /* next free stack position      */
double val[MAXVAL];  /* value stack                   */

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("\n stack full");
}

double pop(void)
{
	if(sp)
		return val[--sp];
	else{
		printf("\n empty stack");
		return 0.0;
	}
}