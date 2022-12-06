#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pe14-1.h"

int main(void)
{
    char m_name[LEN];
    puts("Enter month name (empty line to quit):");
    while (s_gets(m_name, LEN) != NULL && m_name[0] != '\0')
    {
        int count = days(m_name);
        if (count == 0)
        {
            puts("Input error, please input correct month name.");
            puts("Enter month name (empty line to quit):");
            continue;
        }
        
        printf("total days: %d\n", count);
    }

    return 0;
}

int days(char * month_name)
{
    int total = 0;
    for (int i = 0; i < 12; i++)
    {
        total += months[i].days;
        if (strcmp(months[i].name, month_name) == 0)
            break;
    }
    return total;
}

char * s_gets(char * st, int size)
{
    char * ret;
    ret = fgets(st, size, stdin);
    if (ret)
    {
        char * find;
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret;    
}