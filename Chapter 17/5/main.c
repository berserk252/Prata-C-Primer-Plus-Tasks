#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Stack stack;
	Item temp;
	
	InitializeStack(&stack);
	
	if(FullStack(&stack))
	{
		fprintf(stderr,"No memory available! Bye!\n");
        exit(1);
	}
	
	puts("Enter a num (an -100 to quit): ");
	scanf("%d", &temp);
	while( temp != -100)
	{
		if(FullStack(&stack))
		{
			fprintf(stderr,"No memory available! Bye!\n");
        	exit(1);
		}
		
		Push(temp, &stack);        
        printf("Enter next number (-100 to quit): ");
    	scanf("%d", &temp);
	}
	
	while (!EmptyStack(&stack))
    {
    	Pop(&temp, &stack);
		printf("%d ", temp);
    }
    
    puts("Bye!");
	
    return 0;
}

