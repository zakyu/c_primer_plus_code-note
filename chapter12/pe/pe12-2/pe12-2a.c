#include <stdio.h>
#include "pe12-2a.h"

static int mode = 0;
static double distance;
static double consumed_fuel;

void set_mode(int m)
{
    if (m < 0 || m > 1)
    {
        puts("Input mode incorrect, using last used mode.");
        return;
    }
    mode = m;
}

void get_info()
{
    switch(mode)
    {
        case 1:
            puts("US mode: Input distance in mile(s)"
                    " and consumed fuel in gallon(s): ");
            scanf("%lf %lf", &distance, &consumed_fuel);
            break;
        case 0:
            puts("metric mode: Input distance in kilometer(s)"
                    " and consumed fuel in litre(s): ");
            scanf("%lf %lf", &distance, &consumed_fuel);
            break;
    }
}

void show_info()
{
    switch(mode)
    {
        case 0:
            printf("your fuel consumption is %f litre(s) per 100 kilometer.\n",
                    consumed_fuel/distance/100);
            break;
        case 1:
            printf("Your fuel consumption is %f mile(s) per gallon.\n",
                    distance/consumed_fuel);
            break;
    }
}
