#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

void copy_arr( double [], double [], int);
void copy_ptr( double [], double [], int);

int main( void )
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
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

void copy_arr( double source[], double target[], int end)
{
	for(int i = 0; i != end; i++)
	{
		target[i] = source[i];
	}
}

void copy_ptr( double source[], double target[], int end)
{
	double *tPtr = target, *sPtr = source;
	
	for(int i = 0; i != end; i++)
	{
		*tPtr = *sPtr;
		tPtr++;
		sPtr++;
		
	}
}

