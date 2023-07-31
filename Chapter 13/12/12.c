#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int Iarr[20][30] = {0}, i = 0, j = 0;
	char Carr[20][31];
	char ch;
	
	if((fp1 = fopen("aa", "r")) == NULL || (fp2 = fopen("bb", "w")) == NULL)
	{
		printf("Can't open the file");
		exit(1);
	}
	
	ch = getc(fp1);
	while(ch != EOF)
	{
		int n = atoi(&ch);
		if(ch != ' ')
		{
			Iarr[i][j] = n;
			j++;
		}
		if(j == 31)
		{
			j = 0;
			i++;
		}
		ch = getc(fp1);
	}
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			switch(Iarr[i][j])
			{
				case 0 :
					Carr[i][j] = ' ';
					break;
				
				case 1 :
					Carr[i][j] = '.';
					break;
					
				case 2 :
					Carr[i][j] = '\'';
					break;
					
				case 3 :
					Carr[i][j] = ':';
					break;
					
				case 4 :
					Carr[i][j] = '~';
					break;
					
				case 5 :
					Carr[i][j] = '*';
					break;
					
				case 6 :
					Carr[i][j] = '=';
					break;
					
				case 7 :
					Carr[i][j] = '+';
					break;
					
				case 8 :
					Carr[i][j] = '%';
					break;
					
				case 9 :
					Carr[i][j] = '#';
					break;
				
				
			}
		}
	}
	
	for(int i = 0; i < 20; i++)
	{
		Carr[i][30] = '\0';
	}
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			fprintf(fp2 ,"%c", Carr[i][j]);
		}
		fprintf(fp2, "%c", '\n');
	}
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			printf("%c", Carr[i][j]);
		}
		puts("");
	}
	
	fclose(fp1);
	fclose(fp2);
	return 0;
}

