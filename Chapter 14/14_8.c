#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main( void )
{
	struct fullname {
		char fname[20];
		char lname[20];
	};
	struct bard {
		struct fullname name;
		int born;
		int died;
	};
	
	struct bard willie;
	
	willie.born = 2005;
	
	struct bard *pt = &willie;
	
	pt->born = 2004;
	
	scanf("%d", &willie.born);
	
	scanf("%d", pt->born);
	
	scanf("%s", willie.name.lname);
	
	scanf("%s", pt->name.lname);
	
	printf("%c", willie.name.fname[2]);
	
	int a = strlen(willie.name.fname);
	int b = strlen(willie.name.lname);
	
	int sum = a + b;
	
	return 0;
}

