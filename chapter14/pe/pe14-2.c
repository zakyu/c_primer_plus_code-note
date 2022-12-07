#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pe14-2.h"

int main(void)
{
    int day, year;
    char month[LEN];
    puts("Enter day, month and year (q to quit):");
    while (scanf("%d %10s %d", &day, month, &year) == 3)
    {
        is_leap_year(year);
        int total = days(day, month);
        if (total == -1)
            puts("Invalid date!");
        else
            printf("There are %d days from the begin of %d to %s %d\n",
                total, year, month, day);

        months[1].day = 28;
        puts("Enter day, month and year (q to quit):");
    }

    puts("Done.");
    return 0;
}

int days(int day, char * month)
{
    if (day < 1 || day > 31)
        return -1;

    int total = 0, i;
    int temp = atoi(month);

    if(temp == 0)
    {
        month[0] = toupper(month[0]);
        for (i = 1; month[i] != '\0'; i++)
            month[i] = tolower(month[i]);
    }

    for (i = 0; i < 12; i++)
    {
        if (temp == months[i].num
            || strcmp(month, months[i].name) == 0
            || strcmp(month, months[i].abbr) == 0)
        {
            if (day > months[i].day)
                return -1;
            return total + day;
        }
        total += months[i].day;
    }

    return -1;
}

void is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 
            || year % 400 == 0)
        months[1].day = 29;
}