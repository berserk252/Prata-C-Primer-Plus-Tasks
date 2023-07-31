#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

void funct(int arr1[], int arr2[], int arr3[], int n);

int main( void )
{
	int arr1[4] = {1, 3, 0, 4};
	int arr2[4] = {2, 5, 4, 8};
	int arr3[4];

	funct(arr1, arr2, arr3, 4);

	printf("%d, %d, %d, %d", arr3[0], arr3[1], arr3[2], arr3[3]);

	return 0;
}

void funct(int arr1[], int arr2[], int arr3[], int n)
{
	for(int i = 0; i != n; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}
}
