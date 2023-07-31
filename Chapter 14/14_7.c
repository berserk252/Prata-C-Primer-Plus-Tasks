#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct name {
	char first[20];
	char last[20];
};

struct bem {
	int limbs;
	struct name title;
	char type[30];
};

void aaa(struct bem *a);

int main( void )
{
	struct bem * pb;
	struct bem deb = {
		6,
		{"Berbnazel", "Gwolkapwolk"},
		"Arcturan"
	};
	
	pb = &deb;
	
	aaa(pb);
	
	return 0;
}

void aaa(struct bem *a)
{
	printf("%s %s is a %d-limbed %s", a->title.first, a->title.last, a->limbs, a->type);
}

