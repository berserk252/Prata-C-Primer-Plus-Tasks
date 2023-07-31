#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int ch;
    int count = 0;
    int fct;

    if (argc < 3)
    {
        printf("Usage: %s character filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (fct = 2; fct < argc; fct++)
    {
        if ((file = fopen(argv[fct], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[fct]);
        else
        {
            if (ferror(file) != 0)
                fprintf(stderr, "Error in reading file %s.\n",
                        argv[fct]);
            ch = (char)getc(file);
            while (ch != EOF)
            {
                if (argv[1][0] == ch)
                    count++;
                ch = (char)getc(file);
            }
            printf("The character %s has appeared in file %s for %d times.\n",
                    argv[1], argv[fct], count);
            count = 0;
            fclose(file);
        }
    }

    return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char fn[20], ch, i = 2;
	char n = argv[1][0];
	int fold = 0, count = 0;
	if(argc > 2)
	{
		if((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("Cant open the File : %s", argv[2]);
			exit(1);
		}
		fold++;
	}
	else
	{
		printf("Enter first FILE name:");
		gets(fn);
		if((fp = fopen(fn, "r")) == NULL)
		{
			printf("Cant open the File : %s", fn);
			exit(1);
		}
	}
	ch = (char)getc(fp);
	while(1)
	{
		if (ferror(fp) != 0 && fold == 1)
                fprintf(stderr, "Error in reading file %s.\n",
                        argv[i]);
        if (ferror(fp) != 0 && fold == 0)
                fprintf(stderr, "Error in reading file %s.\n",
                        fn);
		while(ch != EOF)
		{
			if(argv[1][0] == ch)
			{
				
				count++;
			}
			ch = (char)getc(fp);
		}
		fclose(fp);
		if(fold == 1)
		{
			printf("In %s file we find %d of %c\n",argv[i], count, n);
			i++;
			if(i == argc)
			{
				break;
			}
			if((fp = fopen(argv[i], "r")) == NULL)
			{
				printf("Cant open the File : %s", argv[i]);
				exit(1);
			}
			
		}
		else
		{
			printf("In %s file we find %d of %c\n",fn, count, n);
			printf("Enter first FILE name :");
			gets(fn);
			if( fn[0] == '\n' || fn[0] == '\0')
			{
				break;
			}
			if((fp = fopen(fn, "r")) == NULL)
			{
				printf("Cant open the File : %s or you quite", fn);
				exit(1);
			}
		}
		
		count = 0;
	}
	
	
	fclose(fp);
	
	return 0;
}
*/
