#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

unsigned int function(unsigned int num, unsigned int shift);

int main( void )
{
	unsigned int num = 186, shift = 4;
	
	printf("Before shift on %d: num is %d\n", shift, num);
	
	num = function(num, shift);
	
	printf("After shift on %d: num is %d\n", shift, num);
	
	return 0;
}

unsigned int function(unsigned int num, unsigned int shift)
{
	unsigned int hold = num;
	
	for(int i = 0; i <= shift; i++)
	{
		num <<= 1;
	}
	
	for(int i = 0; i <= 8 - shift; i++)
	{
		hold >>= 1;
	}
	
	return num |= hold;
	
}

