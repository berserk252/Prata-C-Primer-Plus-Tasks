#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

void print(int arr[][5], int a);
void print2x(int arr[][5], int a);

int main( void )
{
	int arr[3][5] = {{2, 5, 4, 3, 1}, {2, 5, 4, 3, 1}, {2, 5, 4, 3, 1}};
	
	print(arr, 3);
	print2x(arr, 3);

	return 0;
}

void print(int arr[][5], int a)
{
	for(int i = 0; i != a; i++)
	{
		for(int y = 0; y != 5; y++)
		{
			printf("%d ", arr[i][y]);
		}
		puts("");
	}
}

void print2x(int arr[][5], int a)
{
	for(int i = 0; i != a; i++)
	{
		for(int y = 0; y != 5; y++)
		{
			printf("%d ", arr[i][y] *= 2);
		}
		puts("");
	}
}

