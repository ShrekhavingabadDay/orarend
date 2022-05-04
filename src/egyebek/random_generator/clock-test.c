#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "clock.h"
/*
typedef struct Clock
{
    int hrs;
    int min;
}Clock;

Clock Setter(double minutes)
{
    Clock back;
    back.hrs = minutes % 60
    
}
*/
int main(void)
{
    for(int i = 0; i < 10 ; i++)
    {
        int time = random_clock();
        Clock out = clock_compiler(time);
        printf("The time is: %d:%d\n", out.hrs, out.min);
    }
    return 0;
}
