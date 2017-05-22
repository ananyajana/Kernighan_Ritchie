/* write a program to fold long input lines into two or more
shorter lines after the last non-blank character that occurs
before nth column input. make sure your program does something
intelligent with very long input lines and if there are no blanks 
or tabs before the specified column                            */

#include <stdio.h>
#define  TS      8   /* tab increment size */ 
#define  MAXCOL  10  /* maximum column of input  */

char line[MAXCOL];

int exptab(int pos);
int findblnk(int pos);
int nwepos(int pos);
void printl(int pos);


int main()
{
	int c, pos;
	
	pos = 0;			             /* position in the line   */
	while((c = getchar()) != '@'){
		line[pos] = c;				 /* store current position */
		if(c == '\t')				 /* input line             */
			pos = exptab(pos);
		else if(c == '\n'){
			printl(pos);			 /* print current input line */
			pos = 0;
		}
		else if(++pos >= MAXCOL){
			pos = findblnk(pos);
			printl(pos);
			pos = newpos;
		}
	}
}

/* printl prints line until pos column   */
 
void printl(int pos)
{
	int i;
	
	for(i = 0; i < pos; ++i)
		putchar(line[i]);
	if(pos > 0)
		putchar('\n');
}

/* exptab expands tabs to blanks */

int exptab(int pos)
{
	line[pos] = ' ';                      /* tab is at least one blank */
	for( ++pos; pos < MAXCOL && pos % TS != 0; ++pos)
		line[pos] = ' ';
		if(pos < MAXCOL)                  /* room left in current line */
			return pos;
		else{							  /* current line is full      */	
			printl(pos);
			return 0;					  /* reset current position    */
		}
}
	
/* findblnk finds out blank's position  */

int findblnk(int pos)
{
	while(pos > 0 && line[pos] != ' ')
		--pos;
	if(pos == 0)                          /* no blanks in the line     */
		return MAXCOL;					 
	else								  /* at least one blank        */
		return pos + 1;					  /* position after the blank  */
}

/* newpos: rearranges line with new position  */

int newpos(int pos)
{
	int i, j;
	
	if(pos <= 0 || pos >= MAXCOL)
		return 0;         				  /* nothing to rearrange      */	
	else {
		i = 0;
		for(j = pos; j < MAXCOL; ++j){
			line[i] = line[j];
			++i;
		}
		return i;						  /* new position in the line  */
	}
}
			