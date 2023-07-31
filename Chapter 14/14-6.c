#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define MEM 3

struct softball {
	char fname[10];
	char lname[10];
	int tookBall;
	int blowsDelivered;
	int passes;
	int validRuns;
	int averageScore;
};

int main( void )
{
	struct softball players[MEM];
	
	for(int count = 0; count < MEM; count++)
	{
		printf("%d player\n", count + 1);
		printf("Enter first name :");
		scanf("%s", &players[count].fname);
		printf("Enter last name :");
		scanf("%s", &players[count].lname);
		printf("Enter how many times the player received the ball:");
		scanf("%d", &players[count].tookBall);
		printf("Enter how many times the player hit:");
		scanf("%d", &players[count].blowsDelivered);
		printf("Enter how many times the player made passes:");
		scanf("%d", &players[count].passes);
		printf("Enter how many times the player has been counted for runs:");
		scanf("%d", &players[count].validRuns);
	}
	
	for(int count = 0; count < MEM; count++)
	{
		players[count].averageScore = players[count].blowsDelivered / players[count].passes;
	}
	
	for(int count = 0; count < MEM; count++)
	{
		printf("%d %s %s %d %d %d %d average score is : %d\n", count + 1, players[count].fname, players[count].lname, players[count].tookBall, players[count].blowsDelivered, players[count].passes, players[count].validRuns, players[count].averageScore);
		
	}
	
	
	return 0;
}

