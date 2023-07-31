// Τΰιλ pe12-2b.c
#include <stdio.h>
#include "12-2a.h"

static int mode, modeCpy;
static float distance, fuelCons;

int main(void)
{
	
	printf("Enter 0 to select metric mode or 1 to select the regime adopted in the United States:");
	scanf("%d", &mode);
	
	while (mode >= 0)
	{
		get_info();
		modeCpy = mode;
		show_info();
		printf("Enter 0 for metric mode,or 1 for the choice of the regime adopted in the United States\n");
		printf(" (or -1 to exit the program): ");
		scanf("%d", &mode);
	}
	printf("The program has ended.\n");
	return 0;
}

void get_info(void)
{
	
	if(mode > 1)
	{
		printf("You enter incorect number\n");
		
		if(modeCpy == 0)
		{
			printf("Enter the distance traveled in kilometers: ");
			scanf("%f", &distance);
			printf("Enter the amount of fuel used in liters: ");
			scanf("%f", &fuelCons);
			
		}
	
		if(modeCpy == 1)
		{
			printf("Enter the distance traveled in miles: ");
			scanf("%f", &distance);
			printf("Enter the amount of fuel used in gallons: ");
			scanf("%f", &fuelCons);
		}
		
		mode = modeCpy;
	}
	
	if(mode == 0)
	{
		printf("Enter the distance traveled in kilometers: ");
		scanf("%f", &distance);
		printf("Enter the amount of fuel used in liters: ");
		scanf("%f", &fuelCons);
		
	}
	
	if(mode == 1)
	{
		printf("Enter the distance traveled in miles: ");
		scanf("%f", &distance);
		printf("Enter the amount of fuel used in gallons: ");
		scanf("%f", &fuelCons);
	}
}	

void show_info(void)
{
	if(mode == 0)
	{
		printf("Fuel consumption is %.2f liters per 100 km.\n", fuelCons / (distance / 100));
	}
	else
	{
		printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuelCons);
	}
	
}

