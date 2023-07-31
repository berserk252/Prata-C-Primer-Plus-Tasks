#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main( void )
{
	char *str1 = "00111001", *str2 = "01000111", str3[8] = "0";
	
	printf("%s first num\n%s second num\n", str1, str2);
	
	// Operation ~ :
	
	for(int i = 0; i < 8; i++)
	{
		if(str1[i] == '0')
		{
			str3[i] = '1';
		}
		else
		{
			str3[i] = '0';
		}
	}
	
	str3[8] = '\0';
	
	printf("Operation ~ : first string is %s\n", str3);
	
	for(int i = 0; i < 8; i++)
	{
		if(str2[i] == '0')
		{
			str3[i] = '1';
		}
		else
		{
			str3[i] = '0';
		}
	}
	
	printf("Second string is %s\n", str3);
	
	// Operation & :
	
	for(int i = 0; i < 8; i++)
	{
		if(str1[i] == '1' && str2[i] == '1')
		{
			str3[i] = '1';
		}
		else
		{
			str3[i] = '0';
		}
	}
	
	printf("Operation & : expression is %s\n", str3);
	
	// Operation | :
	
	for(int i = 0; i < 8; i++)
	{
		if(str1[i] == '1' || str2[i] == '1')
		{
			str3[i] = '1';
		}
		else
		{
			str3[i] = '0';
		}
	}
	
	printf("Operation | : expression is %s\n", str3);
	
	// Operation ^ : 
	
	for(int i = 0; i < 8; i++)
	{
		if(str1[i] == '1' && str2[i] == '1' || str1[i] == '0' && str2[i] == '0')
		{
			str3[i] = '0';
		}
		else
		{
			str3[i] = '1';
		}
	}
	
	printf("Operation ^ : expression is %s\n", str3);
	
	return 0;
}

