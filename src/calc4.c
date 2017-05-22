/* Add the commands to print the top elements of the stack without popping,
  to duplicate it and to swap the top two elements.Add a command to clear the stack. */
  
#include <stdio.h>
#include <stdlib.h>      /* for atof() function                    */

#define MAXOP 10         /* maximum size of operand or operator    */
#define MAXVAL 10        /* maximum length  of val stack           */ 
#define NUMBER '0'       /* signal that a number was found         */ 
#define BUFSIZE 10


double t[2];             /* top two elements of stack              */  
int sp = 0;              /* next free stack position               */
int flag = 0;
double val[MAXVAL];      /* value stack                            */

char buf[BUFSIZE];       /* buffer for ungetch                     */
int bufp = 0;            /* next free position in bufp             */

double pop(void);
void push(double);
int getop(char []);

int getch(void);
void ungetch(int);

/* reverse polish calculator                      */

int main()
{
     int type;
     double q;
     double op2;
     int op3, op4;
     char s[MAXOP];
	
     while((type = getop(s)) != '@'){
          switch(type){
			
               case NUMBER :
                    push(atof(s));
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

               case '%' :
                    op4 = (int)pop();
                    op3 = (int)pop();
                    if(op4 != 0)
                         push(op3 % op4);
                    else
                         printf("\n zero divisor");
                    break;

               case '\n' :
                    printf("\t%.8g\n", pop());
                    break;
                    
               case 'P':                   /* prints the top two elements */
                    if(sp % 2)
                         printf("\n the top two elements are: %lf %lf\n", t[0], t[1]);
                    else
                         printf("\n the top two elements are: %lf %lf\n", t[1], t[0]);
                    break;       
                   
               case 'S':                   /* swaps the top two elements */
                    q = val[sp - 1];
                    val[sp - 1] = val[sp - 2];
                    val[sp - 2] = q;
                    break;
                    
               case 'D':                   /* duplicates the top two elements */
                    op3 = pop();
                    push(op3);
                    push(op3);
                    break;
                    
               case 'C':                   /* clears the stack */
                    sp = 0;
                    break;
                    
               default :
                    printf("\n unknown command");
               }
	  }
	  return 0;
}

void push(double f)
{
     t[sp % 2] = f;
     if(sp < MAXVAL)
          val[sp++] = f;
     else
     	  printf("\n stack full");
}

double pop(void)
{
     if(sp){
          t[(sp - 2) % 2] = val[sp - 2];
          t[(sp - 3) % 2] = val[sp - 3];
          return val[--sp];
     }
     else{
          printf("\n empty stack");
          return 0.0;
     }
}	


/* getop: get next operator or numeric operand              */

int getop(char s[])
{
     int i, c;
     
     while((s[0] = c = getch()) == ' ' || c == '\t')
          ;
		
     s[1] = '\0';
	
     if(!isdigit(c) && c != '.')
          return c;                     /* not a number  */
	
     i = 0;
	
     if(isdigit(c))                    /* collect integer part */
          while(isdigit(s[++i] = c = getch()))
               ;
	
     if(c == '.')                      /* collect fraction part  */
          while(isdigit(s[++i] = c = getch()))
               ;
	
     s[i] = '\0';
	
     if(c != '@')
          ungetch(c);
     return NUMBER;
}

int getch(void)          /* get a (possibly pushed-back) character */
{
     return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)      /* push character back on input           */
{
     if(bufp >= BUFSIZE)
          printf("ungetch: too many characters \n");
     else
          buf[bufp++] = c;
}
