#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

void print(unsigned long int);

int main( void )
{
	unsigned long int s = 0;
	char chr, chr2;
	int a;
	
	while(1)
	{
		print(s);
		
		printf("Enter the symbol : ");
		scanf("%c", &chr);
		
		switch(chr)
		{
			case 'f' :
				printf("Enter the shrift(0-256): ");
				scanf("%d", &a);
				printf("\n\n\n");
				s |= a;
				break;
			
			case 's' :
				printf("Enter the size of the shrift(0-127): ");
				scanf("%d", &a);
				printf("\n\n\n");
				a <<= 8;
				s |= a;
				
				break;
				
			case 'a' :
				printf("Viberite viravnivanie :\n(0) vlevo (1) po centru (2) v pravo\n");
				scanf("%d", &a);
				printf("\n\n\n");
				if(a == 0)
				{
					s ^= 65536;
				}
				
				if(a == 1)
				{
					if((s & 131072) == 131072)
					{
						s ^= 131072;
					}
					s |= 65536;
				}
				
				if(a == 2)
				{
					s |= 131072;
				}
				
				break;		
		
			case 'b' :
				a <<= 18;
				s ^= a;
				printf("\n\n\n");
				break;
				
			case 'i' :
				a <<= 19;
				s ^= a;
				printf("\n\n\n");
				break;
					
			case 'u' :
				a <<= 20;
				s ^= a;
				printf("\n\n\n");
				break;
				
			case 'q' :
				printf("Vixod\n");
				return 0;
				break;
		}
		a = 1;
	}
	return 0;
}

void print(unsigned long int s)
{
	unsigned long int fold;
	char mask = 0;
	fold = s;
	printf("ID  RAZMER  VIRAVNIVANIE  J     K    CH\n");
	
	mask += fold;
	fold >>= 8;
	
	if(mask < 256)
	{
		printf("%d  ", mask);
	}
	else
	{
		printf("%d  ", (mask >> 8) + 7);
	}
	
	mask = 0;
	mask |= fold;
	fold >>= 8;

	
	printf("%5d  ", mask);
	mask = 3;
	
	mask &= fold;
	fold >>= 2;
	
	switch(mask)
	{
		case 0 :
			printf("\tVLEVO");
			break;
			
		case 1 :
			printf("\tCENTR");
			break;	
			
		case 2 :
			printf("\tVPRAVO");
			break;	
	}
	
	
	mask = 1;
	
	mask &= fold;
	fold >>= 1;
	
	if(mask == 1)
	{
		printf("%8s", "VKL");
	}
	else
	{
		printf("%8s", "VIKL");
	}
	
	mask = 1;
	mask &= fold;
	fold >>= 1;
	
	if(mask == 1)
	{
		printf("%6s", "VKL");
	}
	else
	{
		printf("%6s", "VIKL");
	}
	
	mask = 1;
	mask &= fold;
	fold >>= 1;
	
	if(mask == 1)
	{
		printf("%6s", "VKL\n");
	}
	else
	{
		printf("%6s", "VIKL\n");
	}
	
	
	printf("(f) izmenit shrift  (s)izmenit razmer  (a) izmenit viravnivanie\n");
	printf("(b) polujirniy      (i)kursiv          (u) podcherknutiy\n");
	printf("(q) viyti\n\n");
	
}

