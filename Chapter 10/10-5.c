#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define NUM 10

double max(double []);

int main( void )
{
	double integers[NUM] = {54.5, 89.8, 150.1, 2.2, 457.4, 3.3, 11.1, 41.4, 45.5, 75.7};
	double diferencece;
	
	diferencece = max(integers);
	
	printf("diferencece is %.1f", diferencece);
	
	return 0;
}

double max(double integers[])
{
	float maxNum = 0;
	float minNum = integers[0];
	
	for(int i = 0; i != NUM; i++)
	{
		if(maxNum < integers[i])
		{
			maxNum = integers[i];
		}
		
		if(minNum > integers[i + 1] && i + 1 != NUM)
		{
			minNum = integers[i + 1];
		}
	}
	
	return maxNum - minNum;
}

