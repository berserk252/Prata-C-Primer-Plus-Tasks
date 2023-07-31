#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int binarySearch(int arr[], int size, int n);

int main( void )
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 9;
	
	printf("%d\n", binarySearch(arr, 10, n));
	
	return 0;
}


int binarySearch(int arr[], int size, int n)
{
	int low, high, middle;
	low = 0;
	high = size - 1;
	
	while(low <= high)
	{
		middle = (low + high) / 2;
		if(n > arr[middle])
		{
			low = middle + 1;
		}
		else if(n < arr[middle])
		{
			high = middle - 1;
		}
		else
		{
			return 1;
		}	
	}	
	return 0;
}
