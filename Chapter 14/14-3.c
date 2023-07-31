/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;
    float min[MAXBKS], hold;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        min[count] = library[count].value;
        count++;
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    
    min[0] = library[0].value;
    
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
                   
        printf("\n\nThese are books in alphabetical order:\n\n");           
        
        for(int y = 65; y != 90; y++)
        {
        	for(int i = 0; i != count; i++)
        	{
        		if(toupper(library[i].title[0]) == y)
        		{
        			printf("%s by %s: $%.2f\n", library[i].title,library[i].author, library[i].value);
				}
			}
		}
		
		for(int i = 0; i != count; i++)
		{
			for(int y = 0; y <= count - 2; y++)
			{
				if(min[y] > min[y + 1])
				{
					hold = min[y];
					min[y] = min[y + 1];
					min[y + 1] = hold;
				}
			}
		}
		
		printf("\n\nThese are books on the rise in prices:\n\n");    
		
		for(int i = 0; i != count; i++)
		{
			for(int y = 0; y != count; y++)
			{
				if(min[i] == library[y].value)
				{
					printf("%s by %s: $%.2f\n", library[y].title,library[y].author, library[y].value);
				}
			}
		}
    }
    else
    	printf("No books? Too bad.\n");
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
