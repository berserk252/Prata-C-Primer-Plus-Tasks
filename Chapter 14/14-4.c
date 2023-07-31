#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct name {
	char *fname;
	char *lname;
	char *fathername;
};

struct aaa {
	int num;
	struct name a;
};

int main( void )
{
	struct aaa h[5] = {
		{
			100,
			{
				"Hayko",
				"Mhitaryan",
				"Petrosi"
			}
		},
		
		{
			200,
			{
				"Bagrat",
				"Mhitaryan",
				"Petrosi"
			}
		},
		{
			300,
			{
				"Armen",
				"Mhitaryan",
				"Petrosi"
			}
		},
		{
			400,
			{
				"Arsen",
				"Mhitaryan",
				"Petrosi"
			}
		},
		{
			500,
			{
				"David",
				"Mhitaryan",
				"Petrosi"
			}
		}
	};
	
	for(int i = 0; i < 5; i++)
	{
		printf("%s, %s %c.------%d\n", h[i].a.lname, h[i].a.fname, h[i].a.fathername[0], h[i].num);
	}
	
	return 0;
}

