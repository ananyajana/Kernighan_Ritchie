/* Author: Ananya Jana
write an alternative version of squeeze(s1, s2) that 
deletes each character in s1 that matches any character in s2 */

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main()
{
	char s1[50], s2[10];
	printf("\n enter the string s1: ");
	scanf("%s", &s1);
	printf("\n enter the string s2: ");
	scanf("%s", &s2);
	squeeze(s1, s2);
	printf("\n%s", s1);
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int flag = 0;
	
	for(i = j = 0; s1[i]; ++i){
		for(k = 0; s2[k]; ){
			if(s1[i] == s2[k])
				break;
			else
				++k;
		}	
		if(k == strlen(s2))
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}		
						