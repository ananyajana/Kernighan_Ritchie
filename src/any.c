/* Author: Ananya Jana
write a function any(s1, s2), which returns the first 
location of the string s1 where any character of s2 occurs
or -1 if s1 contains no character of s2                 */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main()
{
	int i;
	char s1[50], s2[10];
	printf("\n enter the string s1: ");
	scanf("%s", &s1);
	printf("\n enter the string s2: ");
	scanf("%s", &s2);
	i = any(s1, s2);
	if(i != -1)
		printf("\n the first position of s1 where some character of s2 occurs is : %d ", i);
}

int any(char s1[], char s2[])
{
	int i, k;
	
	for(i = 0; s1[i]; ++i){
		for(k = 0; s2[k] && s1[i] != s2[k] ; ++k)
			;
		if(k < strlen(s2))
			return i;
	}
	return -1;
}
		 