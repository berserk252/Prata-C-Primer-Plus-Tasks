/* global.c  -- uses an external variable */
#include <stdio.h>
int critic(int units);
int main(void)
{
    int units = 0;  

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while ( units != 56)
    	units = critic(units);
    printf("You must have looked it up!\n");
   
    return 0;
}

int critic(int units)
{
    /* optional redeclaration omitted */
    printf("No luck, chummy. Try again.\n");
    scanf("%d", &units);
    return units;
}
