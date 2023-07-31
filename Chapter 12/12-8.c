// Τΰιλ pe12-8.c
#include <stdio.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int * pa;
	int size;
	int value;
	
	printf("Enter elments: ");
	scanf("%d", &size);
	
	while (size > 0)
	{
		printf("Enter the value for inizalization: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("\nEnter elements(or number < 1 to exit): ");

		scanf("%d", &size);
	}
	
	printf("Program Ended.\n");
	
	return 0;
}

int * make_array(int elem, int val)
{
	int *pa;
	
	pa = (int *)malloc(elem * sizeof(int));
	
	for(int counter = 0; counter != elem; counter++)
	{
		pa[counter] = val;
	}
	return pa;
}

void show_array(const int ar[], int n)
{
	for(int counter = 0; counter != n; counter++)
	{
		if(counter % 8 == 0)
		{
			puts("");
		}
		
		printf("%d ", ar[counter]);
		
		
	}
}
