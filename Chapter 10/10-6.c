#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

void copy_arr( double [][5], double [], int);
void copy_ptr( double [][5], double [], int);

int main( void )
{
	double source[2][5] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
	double target1[5];
	double target2[5];
	copy_arr( source, target1, 5);
	copy_ptr( source, target2, 5);
	
	printf("Target1 = ");
	for(int i = 0; i != 5; i++)
	{
		printf("%.1f ", target1[i]);
	}
	
	puts("");
	
	printf("Target2 = ");
	for(int i = 0; i != 5; i++)
	{
		printf("%.1f ", target2[i]);
	}
	
	puts("");
	
	return 0;
}

void copy_arr( double source[][5], double target[], int end)
{
	for(int i = 0; i != end; i++)
	{
		target[i] = source[0][i];
	}
}

void copy_ptr( double source[][5], double target[], int end)
{
	double *tPtr = target, (*sPtr)[5];
	
	sPtr = source;
	
	for(int i = 0; i != end; i++)
	{
		*tPtr = *(*(sPtr + 1) + i);
		
		tPtr++;
		
	}
}

