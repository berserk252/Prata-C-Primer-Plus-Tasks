#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main( void )
{
	int arr[100] = {1, 5, 100};
	int pass;
	
	srand(time(NULL));
	
	for(int counter = 0; counter != 100; counter++)
	{
		arr[counter] = 1 + rand() % 10;
	}
	
	for(int counter = 0; counter != 100; counter++)
	{
		for(int counter2 = 0; counter2 != 100; counter2++)
		{
			if(arr[counter2] < arr[counter2 + 1])
			{
				pass = arr[counter2 + 1];
				arr[counter2 + 1] = arr[counter2];
				arr[counter2] = pass;
			}
		}
	}
	
	for(int counter = 0; counter != 100; counter++)
	{
		printf("%d\n", arr[counter]);
	}
	
	return 0;
}

