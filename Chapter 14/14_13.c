#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

double a(double,double);
double b(double,double);
double c(double,double);
double d(double,double);


int main( void )
{
	double (*p[4])(double,double);

	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;

	return 0;
}

