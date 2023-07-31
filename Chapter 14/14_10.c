#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct gas {
	float distance;
	float gals;
	float mpg;
};

struct gas aaa(struct gas a);
void bbb(struct gas *a);

int main( void )
{
	struct gas a = {
		24.5,
		5
	};
	struct gas *p = &a;
	
	a = aaa(a);
	bbb(p);
	
	return 0;
}

struct gas aaa(struct gas a)
{
	a.mpg = a.distance / a.gals;
	
	return a;
}

void bbb(struct gas *a)
{
	a->mpg = a->distance / a->gals;
}
