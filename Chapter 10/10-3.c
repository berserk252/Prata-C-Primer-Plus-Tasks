#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define NUM 10

int max(int []);

int main( void )
{
	int integers[NUM] = {54, 89, 150, 2, 457, 3, 11, 41, 0, 75};
	int maxNum;
	
	maxNum = max(integers);
	
	printf("%d\n", maxNum);
	
	return 0;
}

int max(int integers[])
{
	int maxNum = -1;
	 
	for(int i = 0; i != NUM; i++)
	{
		if(maxNum < integers[i])
		{
			maxNum = integers[i];
		}
	}
	
	return maxNum;
}

