#include"1.h"

struct names {
	char first[40];
	char last[40];
};

void showarray(struct names ar[], int n);
int comp(const void * p1, const void * p2);

int main(void)
{
	struct names vals[NUM] = {
		{
			"Armen",
			"Mirakyan"
		},
		
		{
			"Bill",
			"Gates"
		},
		{
			"Will",
			"Smith"
		},
		{
			"Bagrat",
			"Mirakyan"
		},
		{
			"Jecci",
			"Chan"
		}
		
	};
    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(struct names), comp);
    puts("\nSorted list:");
    showarray(vals, NUM);
    return 0;
}

void showarray(struct names ar[], int n)
{
    int index;

    for( index = 0; index < n; index++)
    {
       printf("%s %s\n", ar[index].last, ar[index].first);
    }
    
}

int comp(const void * p1, const void * p2) 
{
	const struct names *ps1 = (const struct names *) p1;
	const struct names *ps2 = (const struct names *) p2;
	int res;
	
	res = strcmp(ps1->last, ps2->last); 
	
	if (res != 0)
		return res;
	else 
		return strcmp(ps1->first, ps2->first);
}
