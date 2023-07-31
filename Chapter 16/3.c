#include"1.h"

struct degree {
	double a;
	double r;
};

struct degree func(struct degree coord);

int main( void )
{
	struct degree coord = {0, 0};	
	
	printf("Enter module and degree:");
	scanf("%lf %lf", &coord.a, &coord.r);
	
	coord = func(coord);
	
	printf("x = %f\ny = %f", coord.a, coord.r);
	return 0;
}

struct degree func(struct degree coord)
{
	double x, y;
	
	x = coord.r * cos(coord.a);
	y = coord.r * sin(coord.a);
	
	coord.a = x;
	coord.r = y;
	
	return coord;
	
}

