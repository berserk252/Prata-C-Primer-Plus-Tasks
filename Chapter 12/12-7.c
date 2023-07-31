#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int dices, rollTimes, sides;

int main( void )
{
	int sum = 0;
	
	srand(time(NULL));
	
	printf("Enter the number of shots or -1 to end the program.\n");
	scanf("%d", &rollTimes);
	
	for(;rollTimes != -1;)
	{
		printf("How many faces and how many dices?\n");
		scanf("%d%d", &sides, &dices);
		
		printf("We have %d throws of %d %d-sided dice.\n", rollTimes, dices, sides);
		
		for(int counter = 0; counter != rollTimes; counter++)
		{
			for(int count = 0; count != dices; count++)
			{
				sum += 1 + rand() % sides;
			}
			
			if(counter % 15 == 0)
			{
				puts("");
			}
			
			printf("%d ", sum);
			
			sum = 0;
		}
		
		printf("\nEnter the number of shots or -1 to end the program.\n");
		scanf("%d", &rollTimes);
	}
	

	return 0;
}

