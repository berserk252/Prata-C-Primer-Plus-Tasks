#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int function(int counter);

int main( void )
{
	int counter = 0;
	
	while(counter != 100)
	{
		counter = function(counter);
	}
	
	printf("%d", counter);
	
	return 0;
}

int function(int counter)
{
	counter++;
	return counter;
}

