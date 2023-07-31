#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct month{
	char *name;
	char abb[4];
	int days;
	int num;
};
	
int main( void )
{
	
struct month year[12] = {
		{
			.name = "January",
			.abb ="Jan",
			.days = 31,
			.num = 1
		},
		{
			.name = "February",
			.abb ="Feb",
			.days = 29,
			.num = 2
		},
		{
			.name = "March",
			.abb ="Mar",
			.days = 31,
			.num = 3
		},
		{
			.name = "April",
			.abb ="Apr",
			.days = 30,
			.num = 4
		},
		{
			.name = "May",
			.abb ="May",
			.days = 31,
			.num = 5
		},
		{
			.name = "June",
			.abb ="Jun",
			.days = 30,
			.num = 6
		},
		{
			.name = "July",
			.abb ="Jul",
			.days = 31,
			.num = 7
		},
		{
			.name = "August",
			.abb ="Aug",
			.days = 31,
			.num = 8
		},
		{
			.name = "September",
			.abb ="Sep",
			.days = 30,
			.num = 9
		},
		{
			.name = "October",
			.abb ="Oct",
			.days = 31,
			.num = 10
		},
		{
			.name = "November",
			.abb ="Nov",
			.days = 30,
			.num = 11
		},
		{
			.name = "December",
			.abb ="Dec",
			.days = 31,
			.num = 12
		}
};
	int d;
	int month;
	int y, sum = 0;
	
	printf("Enter day:");
	scanf("%d", &d);
	printf("Enter num of month:");
	scanf("%d", &month);
	printf("Enter how many years will be passed:");
	scanf("%d", &y);
	
	if( y == 1)
	{
		for(int a = 0; a <= month; a++)
		{
			for(int i = 0; i != d; i++)
			{
				sum += 1;
			}
		}
	}
	else
	{
		for(; y != 0; y--)
		{
			if(y != 1)
			{
				for(int i = 0; i < 12; i++)
				{
					for(int a = 0; a != d; a++)
					{
						sum += 1;
					}
				}
			}
		}
	}
	
	printf("Passed %d days", sum);
	
	return 0;
}

