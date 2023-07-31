#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define CSIZE 4

struct name {
	char fname[15];
	char lname[15];
};

struct student {
	struct name a;
	float grade[3];
	float average;
};

int main( void )
{
	struct student FIO[CSIZE];
	
	for(int counter = 0; counter <= 3; counter++)
	{
		printf("Enter your first name :");
		scanf("%s", &FIO[counter].a.fname);
		printf("Enter your last name :");
		scanf("%s", &FIO[counter].a.lname);
		printf("Enter your grades:");
		scanf("%f%f%f", &FIO[counter].grade[0], &FIO[counter].grade[1], &FIO[counter].grade[2]);
	}
	
	for(int counter = 0; counter < CSIZE; counter++)
	{
		FIO[counter].average = (FIO[counter].grade[0] + FIO[counter].grade[1] + FIO[counter].grade[2]) / 3;
	}
	
	for(int counter = 0; counter < CSIZE; counter++)
	{
		printf("Student: %s %s\n", FIO[0].a.fname, FIO[0].a.lname);
		printf("Student grades: %.2f %.2f %.2f\n" , FIO[counter].grade[0], FIO[counter].grade[1], FIO[counter].grade[2]);
		printf("Average is %.2f\n", FIO[counter].average );
	}
	
	printf("All students average is %.2f", (FIO[0].average + FIO[1].average + FIO[2].average + FIO[3].average) / 4);	
	
	
	return 0;
}

