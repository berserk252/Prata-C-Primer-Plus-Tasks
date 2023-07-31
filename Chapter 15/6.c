#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

struct settings{
	unsigned long int inde_Srift : 8;
	unsigned long int raz_Srift  : 7;
	unsigned long int            : 1;
	unsigned long int virav      : 2;
	unsigned long int bold       : 1;
	unsigned long int kursiv     : 1;
	unsigned long int podcherk   : 8;
};

void print(struct settings s);

int main( void )
{
	struct settings s = {0};
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
				printf("Enter the shrift(0-127): ");
				scanf("%d", &a);
				printf("\n\n\n");
				s.inde_Srift = a;
				break;
			
			case 's' :
				printf("Enter the size of the shrift(0-127): ");
				scanf("%d", &a);
				printf("\n\n\n");
				s.raz_Srift = a;
				break;
				
			case 'a' :
				printf("Viberite viravnivanie :\n(0) vlevo (1) po centru (2) v pravo\n");
				scanf("%d", &a);
				printf("\n\n\n");
				switch(a)
				{
					case 0 :
						s.virav = 0;
						break;
						
					case 1 :
						s.virav = 1;
						break;
						
					case 2 :
						s.virav = 2;
						break;		
				}
				break;		
		
			case 'b' :
				s.bold ^= 1;
				printf("\n\n\n");
				break;
				
			case 'i' :
				s.kursiv ^= 1;
				printf("\n\n\n");
				break;
					
			case 'u' :
				s.podcherk ^= 1;
				printf("\n\n\n");
				break;
				
			case 'q' :
				printf("Vixod\n");
				return 0;
				break;
		}
		
	}
	return 0;
}

void print(struct settings s)
{
	printf("ID  RAZMER  VIRAVNIVANIE  J     K    CH\n");
	printf("%d  %5d", s.inde_Srift, s.raz_Srift);
	switch(s.virav)
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
	
	if(s.bold == 1)
	{
		printf("%8s", "VKL");
	}
	else
	{
		printf("%8s", "VIKL");
	}
	
	if(s.kursiv == 1)
	{
		printf("%6s", "VKL");
	}
	else
	{
		printf("%6s", "VIKL");
	}
	
	if(s.podcherk == 1)
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

