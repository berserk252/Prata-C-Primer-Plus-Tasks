#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20

int main(int argc, char *argv[])
{
	FILE *fp;
	char *chp, ch;
	char arr[SIZE];
	if(argc != 3)
	{
		printf("too few argument in console");
		exit(1);
	}
	
	if((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Can not open the file %s", argv[2]);
		exit(1);
	}
	fgets(arr, SIZE, fp);
	chp = strstr(arr, argv[1]);
	while(chp != NULL)
	{
		printf("%s\n", arr);
		ch = getc(fp);
		while(ch != '\n' && ch != EOF)
		{
			ch = getc(fp);
		}
		if(ch == EOF)
		{
			break;
		}
		fgets(arr, SIZE, fp);
		chp = strstr(arr, argv[1]);	
	}
	
	fclose(fp);
	return 0;
}

