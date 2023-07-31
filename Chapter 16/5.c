#include"1.h"

void lot(int *arr, int size, int lot_size);

int main( void )
{
	int arr[SIZE], num;
	srand(time(NULL));
	
	printf("Enter how many lots do you want to print:");
	scanf("%d", &num);
	
	for(int i = 0; i != SIZE; i++)
	{
		arr[i] = 1 + rand() % 1000;
	}
	
	lot(arr, SIZE, num);
	return 0;
}

void lot(int *arr, int size, int lot_size)
{
	int r;
	
	for(int i = 0; i != lot_size; )
	{
		r = 0 + rand() % (size - 1);
		if(arr[r] != -1)
		{
			printf("N%d = %d\n", i + 1, arr[r]);
			arr[r] = -1;
			i++;
		}
	}
}
