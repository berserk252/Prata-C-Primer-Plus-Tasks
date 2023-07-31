#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int function(int a);

int main( void )
{
	int num = 45;
	int mask = 1, counter = 0;
	
	for(int i = 0; i != 8; i++)
	{
		if((num & mask) == mask)
		{
			counter++;
		}
		num >>= 1;
	}
	
	printf("%d\n", counter);
	
	return 0;
}

int function(int a)
{
	
}
