/* write a program to implement shellsort 
: v[0], v[1], ...v[n - 1] in increasing order  */

#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
	int a[5], n, i;
	
	printf("enter the numbers: ");
	for(i = 0; i < 5; ++i)
		scanf("%d", &a[i]);
	shellsort(a, 5);
	printf("the sorted array is: ");
	for(i = 0; i < 5; ++i)
		printf(" %d", a[i]);	
}

void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	
	for(gap = n / 2; gap > 0; gap /= 2)
		for(i = gap; i < n; ++i)
			for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
				temp = v[j + gap];
				v[j + gap] = v[j];
				v[j] = temp;
			}
}