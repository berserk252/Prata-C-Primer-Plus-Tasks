#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define A(x, y) if(x < y){ return x;} else {return y;}
#define EVEN_GT(x,y) if(x % 2 == 0 && x > y){return 1;}
#define B(x, y) printf(#x " = %d and " #y " = %d", x, y);
#define C(x) const int b##x = 25
#define SPACE ' '
#define PS(x) printf("%c", x);
#define BIG(x) (x * 3)
#define SUMSQ(X,Y) ((x * x) + (y * y))
#define D(x, y, i) printf("name:" #x ",\n" "sum:" #y ",\n" "address:" #i);
#define PR_DATE printf(__TIME__);
int comp(const void *, const void *);

int main( void )
{
	int a[1000];
	double data1[100], data2[300] = {1, 2, 3};
	qsort(a, 1000, sizeof(int), comp);
	
	memcpy(data1, data2, 100);
	
	printf("%f, %f, %f", data1[0], data1[1], data1[2]);
	
	memcpy(data1, data2 + 200, 100);
	
	return 0;
}

int comp(const void *p1, const void *p2)
{
const int * a1 = (const int *) p1;
const int * a2 = (const int *) p2;
	if (*a1 > *a2)
		return 1;
	else if (*a1 == *a2)
		return 0;
	else
		return -1;
}
