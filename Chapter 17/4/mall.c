/* mall.c -- use the Queue interface */
/* compile with queue.c              */
#include <stdio.h>
#include <stdlib.h>    /* for rand() and srand() */
#include <time.h>      /* for time()             */
#include "queue.h"     /* change Item typedef    */
#define MIN_PER_HR 60.0

bool newcustomer(double x);   /* is there a new customer? */
Item customertime(long when); /* set customer parameters  */

struct aa
{
	Queue line;
    Item temp;               /* new customer data             */            
    long turnaways;      /* turned away by full queue     */
    long customers;      /* joined the queue              */
    long served;         /* served during the simulation  */
    long sum_line;       /* cumulative line length        */
    int wait_time;       /* time until Sigmund is free    */
    long line_wait;
};

struct bb
{
	Queue line;
    Item temp;               /* new customer data             */
    long turnaways;      /* turned away by full queue     */
    long customers;      /* joined the queue              */
    long served;         /* served during the simulation  */
    long sum_line;       /* cumulative line length        */
    int wait_time;       /* time until Sigmund is free    */
    long line_wait;
};

int main(void)
{
	int hours;               /* hours of simulation           */
    int perhour;             /* average # of arrivals per hour */
    long cycle, cyclelimit;  /* loop counter, limit           */
    double min_per_cust;     /* average time between arrivals */
	struct aa window1;
	struct bb window2;
    window1.turnaways = 0;
	window2.turnaways = 0;      
    window1.customers = 0;  
	window2.customers = 0;     
    window1.served = 0;
	window2.served = 0;      
    window1.sum_line = 0;  
	window2.sum_line = 0;    
    window1.wait_time = 0;
	window2.wait_time = 0;  
    window1.line_wait = 0;  
	window2.line_wait = 0;     

    InitializeQueue(&window1.line);
    InitializeQueue(&window2.line);
    srand(time(0));          /* random initializing of rand() */
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours for first window and second window:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour for first window and second window:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&window1.line))
                window1.turnaways++;
            else
            {
                window1.customers++;
                window1.temp = customertime(cycle);
                EnQueue(window1.temp, &window1.line);
            }
        }
        if (window1.wait_time <= 0 && !QueueIsEmpty(&window1.line))
        {
            DeQueue (&window1.temp, &window1.line);
            window1.wait_time = window1.temp.processtime;
            window1.line_wait += cycle - window1.temp.arrive;
            window1.served++;
        }
        if (window1.wait_time > 0)
            window1.wait_time--;
        window1.sum_line += QueueItemCount(&window1.line);
        
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&window2.line))
                window2.turnaways++;
            else
            {
                window2.customers++;
                window2.temp = customertime(cycle);
                EnQueue(window2.temp, &window2.line);
            }
        }
        
        if (window2.wait_time <= 0 && !QueueIsEmpty(&window2.line))
        {
            DeQueue (&window2.temp, &window2.line);
            window2.wait_time = window2.temp.processtime;
            window2.line_wait += cycle - window2.temp.arrive;
            window2.served++;
        }
        if (window2.wait_time > 0)
            window2.wait_time--;
        window2.sum_line += QueueItemCount(&window2.line);
    }
    
    
	
	puts("");
	puts("");
	puts("First window:");
    if (window1.customers > 0)
    {
        printf("customers accepted: %ld\n", window1.customers);
        printf("  customers served: %ld\n", window1.served);
        printf("       turnaways: %ld\n", window1.turnaways);
        printf("average queue size: %.2f\n",
              (double) window1.sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n",
              (double) window1.line_wait / window1.served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&window1.line);
    
    puts("");
    puts("");
    puts("Second window");
    if (window2.customers > 0)
    {
        printf("customers accepted: %ld\n", window2.customers);
        printf("  customers served: %ld\n", window2.served);
        printf("       turnaways: %ld\n", window2.turnaways);
        printf("average queue size: %.2f\n",
              (double) window2.sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n",
              (double) window2.line_wait / window2.served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&window2.line);
    
    puts("Bye!");

    return 0;
}

/* x = average time, in minutes, between customers       */
/* return value is true if customer shows up this minute */
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

/* when is the time at which the customer arrives            */
/* function returns an Item structure with the arrival time  */
/* set to when and the processing time set to a random value */
/* in the range 1 - 3                                        */
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
  
    return cust;
}

