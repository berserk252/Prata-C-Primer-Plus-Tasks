#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int cpy(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	
	if(argc < 2)
	{
		printf("Usage: %s filename\n", argv[0]);
        exit(1);
	}
	
	if ((fp1 = fopen(argv[1], "r+")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }
    
    if ((fp2 = fopen(argv[2], "w+")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(1);
    }
    
    cpy(fp1, fp2);
	
	return 0;
}

int cpy(FILE *fp1, FILE *fp2){
	int bytes, arr[100];
	while(bytes = fread(arr, sizeof(int), 100, fp1) > 0)
		fwrite(arr, sizeof(int), 100, fp2);
}
