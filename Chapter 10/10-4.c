#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define NUM 10

int max(double []);

int main( void )
{
	double integers[NUM] = {54.5, 89.8, 150.1, 2.2, 457.4, 3.3, 11.1, 41.4, 0, 75.7};
	int index;
	
	index = max(integers);
	
	printf("%d = %.1f\n", index, integers[index]);
	
	return 0;
}

int max(double integers[])
{
	float maxNum = 0;
	int index;
	
	for(int i = 0; i != NUM; i++)
	{
		if(maxNum < integers[i])
		{
			maxNum = integers[i];
			index = i;
		}
	}
	
	return index;
}

