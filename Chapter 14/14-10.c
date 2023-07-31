#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#define SEATS 12

struct airoport {
	int seatNum;
	int mark;
	char fname[10];
	char lname[10];
};

void a( struct airoport *flight);
void b( struct airoport *flight);
void c( struct airoport *flight);
void d( struct airoport *flight);
void e( struct airoport *flight);

int main( void )
{
	struct airoport flight[SEATS] = {
		0
	};
	char chr;
	int count = 1;
	struct airoport *flp;
	flp = &flight[0];
	
	while(count != 0)
	{
		printf("To select a function, enter its letter designation:\n");
		printf("a) Show the number of free seats\n");
		printf("b) Show the list of empty or free seats\n");
		printf("c) Show alphabetical list of occupied positions\n");
		printf("d) Assign a seat to the passenger\n");
		printf("e) Remove seat assignment\n");
		printf("f) Exit the program\n");
		chr = getchar();
		
		
		switch(chr)
		{
			case 'a':
				a(flight);
				break;
			
			case 'b':
				b(flight);
				break;
			
			case 'c':
				c(flight);
				break;
				
			case 'd':
				d(flight);
				break;
				
			case 'e':
				e(flight);
				break;
				
			case 'f':
				count = 0;
				break;					
		}
		
	}
	
	
	

	return 0;
}

void a( struct airoport *flight)
{
	for(int count = 0; count < SEATS; count++)
	{
		if(flight[count].mark == 0)
		{
			printf("%d seat is free\n", count + 1);
		}
	}
}

void b( struct airoport *flight)
{
	for(int count = 0; count < SEATS; count++)
	{
		if(flight[count].mark == 0)
		{
			printf("%d seat is free\n", count);
		}
		else
		{
			printf("%d seat is reserved\n", count);
		}
	}
}

void c( struct airoport *flight)
{
	for(int count = 0; count < SEATS; count++)
	{
		if(flight[count].mark == 1)
		{
			printf("%c%d seat is reserved\n", 65 + count, count);
		}
	}	
}

void d( struct airoport *flight)
{
	for(int count = 0; count < SEATS; count)
	{
		if(flight[count].mark == 0)
		{
			printf("Enter your first name: ");
			scanf("%s", &flight[count].fname);
			printf("Enter your last name: ");
			scanf("%s", &flight[count].lname);
			flight[count].mark = 1;
			
			printf("The seat is reserved, your seat is %d\n", count + 1);
			break;
		}
	}
}

void e( struct airoport *flight)
{
	int number;
	
	printf("Enter your seat number:");
	scanf("%d", &number);
	
	number--;
	
	flight[number].mark = 0;
}
