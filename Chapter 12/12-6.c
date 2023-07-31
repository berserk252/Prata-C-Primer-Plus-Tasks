#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main( void )
{
	int arr[100] = {0};
	int arrCounter[100] = {0};
	int pass;
	
	srand(time(NULL));
	
	for(int counter = 0; counter != 100; counter++)
	{
		arr[counter] = 1 + rand() % 10;
	}
	
	for(int counter = 0; counter != 100; counter++)
	{
		arrCounter[arr[counter]]++; 
	}
	
	for(int counter = 0; counter != 10; counter++)
	{
		printf("Number %d reapeted %d times\n", counter, arrCounter[counter]);
	}
	
	return 0;
}

