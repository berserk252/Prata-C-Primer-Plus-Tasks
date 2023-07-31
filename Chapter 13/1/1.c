/* count.c -- using standard I/O */
#include <stdio.h>

#include <stdlib.h> // ANSI C exit() prototype
int main(int argc, char *argv[])
{
    int ch;         // place to store each character as read
    FILE *fp;       // "file pointer" 
    long count = 0;
	char fname[20];
	
	printf("Enter the file name:");
	scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("Can't open %s\n", fname);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
    {
       putc(ch,stdout);  // same as putchar(ch);
       count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", fname, count);
    
    return 0;
}
