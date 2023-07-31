#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char word[100];
	long pos;
	char ch;
	
	printf("Enter file name:");
	gets(word);
	
	if((fp = fopen(word, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s", word);
		exit(1);
	}
	
	printf("Enter position:");
	scanf("%l", pos);
	
	fseek(fp, pos, SEEK_SET);
	ch = getc(fp);
	while(ch != '\n' && ch != EOF)
	{
		putchar(ch);
		ch = getc(fp);
		/*if(ch == EOF || ch == '\n' || ch == NULL)
			break;*/
	}
	
	return 0;
}

