/* Author: Ananya Jana
write a program to find a number in 
a given sortedlist using binry search */

#include <stdio.h>

int bin_search(int x, int a[], int i);
int main()
{
	int a[8], x, i;
	printf("\n enter the sorted array: ");
	for(i = 0; i < 8; ++i)
		scanf("%d", &a[i]);
	printf("\n enter the no. to be searched: ");
	scanf("%d", &x);
	if(bin_search(x, a, i))
		printf("\n the no. is in the list ");
	else
		printf("\n the no. is not in the list ");
}

int bin_search(int x, int a[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < a[mid])
			high = mid - 1;
		else if(x > a[mid])
			low = mid + 1;
		else
			return x;
	}
	return 0;
}
			
	