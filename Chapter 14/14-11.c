#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define SIZE 50

double sin(double source);
void transform(double source[], double target[], int size, double (*sinP)(double));
void print(double target[]);

int main( void )
{
	double (*sinP)(double);
	double source[SIZE];
	double target[SIZE];
	
	sinP = sin;
	
	srand(time(NULL));
	
	for(int count = 0; count < SIZE; count++)
	{
		source[count] = 1 + rand() % 10;
	}
	
	transform(source, target, SIZE, sinP);
	
	print(target);
	
	return 0;
}

void transform(double source[], double target[], int size, double (*sinP)(double))
{
	for(int count = 0; count < size; count++)
	{
		target[count] = sinP(source[count]);
	}
}

double sin(double source)
{
	return source * source;
}

void print(double target[])
{
	for(int count = 0; count < SIZE; count++)
	{
		printf("%.1f ", target[count]);
		
		if(count % 10 == 0 && count != 0)
		{
			puts(" ");
		}
	}
}
