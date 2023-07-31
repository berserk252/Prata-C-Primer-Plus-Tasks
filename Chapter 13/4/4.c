#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("You dont enter file names please try again");
		exit(1);
	}	
	
	for(int i = 1; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	

	
	return 0;
}

