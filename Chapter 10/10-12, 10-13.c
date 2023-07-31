#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

double b( double arr[], int n);
double v( int n, int m, double arr[][m]);
double g( int n, int m, double arr[][m]);
void d( double b[], double v, double g, int n);

int main( void )
{
	double arr[3][5] = {{2.1, 5.5, 6.7, 12.1, 3.4}, {4.5, 13.6, 7.7, 12.6, 9.9}, {11.1, 7.4, 5.5, 8.8, 1.1}};
	double bSum[3], vSum, gSum;
	int n = 3, m = 5;
	
	for(int i = 0; i != n; i++)
	{
		bSum[i] = b(arr[i], m);
	}
	
	vSum = v(n, m, arr);
	
	gSum = g(n, m, arr);
	
	d(bSum, vSum, gSum, n);
		
	return 0;
}

double b(double arr[], int n)
{
	double sum = 0;
	
	for(int i = 0; i != n; i++)
	{
		sum += arr[i];
	}
	
	return sum / n;
}

double v( int n, int m, double arr[][m])
{
	double sum = 0;
	
	for(int i = 0; i != n; i++)
	{
		for(int y = 0; y != m; y++)
		{	
			sum += arr[i][y];
		}
	}
	
	return sum / (n * m);
}

double g( int n, int m, double arr[][m])
{
	double max = 0;
	
	for(int i = 0; i != n; i++)
	{
		for(int y = 0; y != m; y++)
		{
			if(max < arr[i][y])
			{
				max = arr[i][y];
			}
		}
	}
	
	return max;
}

void d( double b[], double v, double g, int n)
{
	printf("The first pack average is %.2f\n", b[0]);
	printf("The second pack average is %.2f\n", b[1]);
	printf("The third pack average is %.2f\n", b[2]);
	printf("The all integers average is %.2f\n", v);
	printf("The largest number is %.2f\n", g);
}
