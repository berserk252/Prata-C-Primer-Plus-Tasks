#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int change(char *pbin);

int main( void )
{
	char * pbin = "01001001";
	
	int sum = change(pbin);
	
	printf("%d\n", sum);
	
	return 0;
}

int change(char *pbin)
{
	int a = 1, sum = 0;
	
	for(int i = 7; i >= 0; i--)
	{
		if(pbin[i] == '1')
		{
			sum += a;
		}
		a *= 2;	
	}
	
	return sum;
}

