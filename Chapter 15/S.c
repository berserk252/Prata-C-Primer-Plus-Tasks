#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct {
	unsigned int a: 2;
	unsigned int : 1;
	unsigned int b: 2;
	unsigned int : 1;
	unsigned int : 2;
};

struct {
	unsigned int c: 2;
	unsigned int : 1;
	unsigned int b: 2;
	unsigned int : 1;
	unsigned int a: 2;
};

int main( void )
{
	//00000011
	//00001101
	//00111011
	//01110111
	
	//2:
	
	//21
	//85
	//76
	//156
	
	//3:
	
	//11111100
	//00000010
	//00000111
	//00000111
	//00000101
	//00000011
	//00011100
	
	//4:
	
	//11111111
	//00000000
	//00000000
	//00000000
	//00000110
	//00101000
	
	
	
	return 0;
}

