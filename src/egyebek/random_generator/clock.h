#include <bits/types/clock_t.h>
#include <stdlib.h>
#include <time.h>

typedef struct Clock
{
    int hrs;
    int min;
}Clock;

Clock clock_compiler(int minute);
int random_clock(void);
