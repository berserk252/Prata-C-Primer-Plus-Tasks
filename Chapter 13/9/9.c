/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main(void)
{
    FILE *fp, *fp1;
    char words[MAX], count = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout,"Can't open \"words\" file.\n");
        exit(1);
    }
    
    if ((fp1 = fopen("aa", "rb")) == NULL)
    {
        fprintf(stdout,"Can't open \"aa\" file.\n");
        exit(1);
    }
    
	fseek(fp1, 0L, SEEK_SET);
    fread(&count, sizeof(int), 1, fp1);
    
    printf("Enter words to add to the file(In file you have %d words); press the Enter\n", count);
    puts("key at the beginning of a line to terminate.");
    while (gets(words) != NULL  && words[0] != '\0')
    {
    	fprintf(fp, "%s ", words);
		count++;
	}
     
    puts("File contents:");
    rewind(fp);           /* go back to beginning of file */
    int i = 1;
    while (fscanf(fp,"%s",words) == 1)
    {
    	printf("%d: ", i);
    	i++;
    	puts(words);
	}
	fclose(fp1);
	if ((fp1 = fopen("aa", "wb")) == NULL)
    {
        fprintf(stdout,"Can't open \"aa\" file.\n");
        exit(1);
    }
	fwrite(&count, sizeof(int), 1, fp1);
     
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    if (fclose(fp1) != 0)
        fprintf(stderr,"Error closing file\n");
     
    return 0;
}
