#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct month{
	char *name;
	char abb[4];
	int days;
};
	
int main( void )
{
	
	struct month year[12] = 
	{
		{
			.name = "January",
			.abb ="Jan",
			.days = 31,
		},
		{
			.name = "February",
			.abb ="Feb",
			.days = 29,
		},
		{
			.name = "March",
			.abb ="Mar",
			.days = 31,
		},
		{
			.name = "April",
			.abb ="Apr",
			.days = 30,
		},
		{
			.name = "May",
			.abb ="May",
			.days = 31,
		},
		{
			.name = "June",
			.abb ="Jun",
			.days = 30,
		},
		{
			.name = "July",
			.abb ="Jul",
			.days = 31,
		},
		{
			.name = "August",
			.abb ="Aug",
			.days = 31,
		},
		{
			.name = "September",
			.abb ="Sep",
			.days = 30,
		},
		{
			.name = "October",
			.abb ="Oct",
			.days = 31,
		},
		{
			.name = "November",
			.abb ="Nov",
			.days = 30,
		},
		{
			.name = "December",
			.abb ="Dec",
			.days = 31,
		}
	};
		
	char s[10];
	
	printf("Enter a month name(first uppercase next symbols lowcase letters):");
	scanf("%s", s);
	
	for(int i = 0; i < 12; i++)
	{
		if(strcmp(year[i].name, s) == 0)
		{
			printf("The %s(%s) have %d days\n", year->name, year->abb, year->days);
			break;
		}
	}
	
	return 0;
}



