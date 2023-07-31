// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h>    // for exit()
#include <string.h>    // for strcpy(), strcat()
#define LEN 40

int main(int argc, char *argv[])
{
    FILE  *in, *out;   // declare two FILE pointers
    int ch;
    char name[LEN], fn1[LEN];    // storage for output filename
    int count = 0;
    
// check for command-line arguments 
    printf("Enter first file name:");
    scanf("%s", fn1);
// set up input
    if ((in = fopen(fn1, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                fn1);
        exit(2);
    }
// set up output    
    strncpy(name,fn1, LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name,".red");            // append .red  
    if ((out = fopen(name, "w")) == NULL)
    {                       // open file for writing
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
// copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
// clean up    
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    
    return 0;
}

