#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
int cpy(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char fn1[20], fn2[20];
	
	printf("Enter first name of file:");
	scanf("%s", fn1);
	
	if((fp1 = fopen(fn1, "r")) == NULL)
	{
		printf("Can't open the file : %s", fn1);
		exit(1);
	}
	
	printf("Enter second name of file:");
	scanf("%s", fn2);
	
	if(strcmp(fn1,fn2) == 0)
	{
		printf("We can't copy the same files");
		exit(1);
	}
	
	if((fp2 = fopen(fn2, "w")) == NULL)
	{
		printf("Can't open the file : %s", fn2);
		exit(1);
	}
	cpy(fp1, fp2);
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

int cpy(FILE *fp1, FILE *fp2)
{
	char a;
	a = getc(fp1);
	while (a != EOF)
	{
		a = toupper(a);
		putc(a, fp2);
		a = getc(fp1);
	}
		
}
