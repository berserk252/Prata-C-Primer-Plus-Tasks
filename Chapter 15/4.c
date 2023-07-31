#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int function(int num, int bits);

int main( void )
{
	int num = 2, bits = 3, result;
	
	result = function(num, bits);
	
	if(result == 1)
	{
		printf("%d bit is truned on\n", bits);
	}
	else
	{
		printf("%d bit is truned of\n", bits);
	}
	
	return 0;
}

int function(int num, int bits)
{
	int mask = 1;
	
	for(int i = 0; i != (bits - 1); i++)
	{
		mask <<= 1;
	}
	
	if((num & mask) == mask)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
