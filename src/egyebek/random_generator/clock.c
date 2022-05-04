#include <stdio.h>
#include <stdlib.h>
#include "clock.h"
#include <time.h>
Clock clock_compiler(int interval)
{
    Clock back;
    int hours = 0;
    while(interval > 60)
    {
        interval = interval - 60;
        hours ++;
    }
    back.hrs = hours;
    back.min = interval;    
    return back;
}

int random_clock(void)
{
    srand(time(NULL));
    int mn;
    mn = rand();
    mn = mn % 1000;
/*dontfit:mn = mn % 1000;
    if((mn %10 ) != 0)goto dontfit;*/
    return mn;
}
