#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pe14-3.h"

int main(void)
{
    BOOK library[MAXBKS];
    int count = 0;
    int index;

    puts("Please enter the book title.");
    puts("Press [enter] at the start of a line to stop.");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
            && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        count++;
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.\n");
    }

    if (count > 0)
    {
        print_book(library, count, by_default);
        print_book(library, count, by_title);
        print_book(library, count, by_price);
    }
    else
        puts("No books? Too bad.");

    return 0;
}

void print_book(BOOK * const library, int count, SORT_FUNC sort)
{
    BOOK * order[count];

    for (int i = 0; i < count; i++)
        order[i] = &library[i];
    sort(order, count);
    
    puts("\nHere is the list of your books:");
    for (int index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", order[index]->title,
                order[index]->author, order[index]->value);
}

void by_default(BOOK *order[], int count){}

void by_title(BOOK *order[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int min = i;
        for (int j = i+1; j < count; j++)
            if (strcmp((*(order+min))->title, (*(order+j))->title) > 0)
                min = j;

        if (i != min)
        {
            BOOK * ptemp = order[i];
            order[i] = order[min];
            order[min] = ptemp;
        }
    }
}

void by_price(BOOK *order[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int min = i;
        for (int j = i+1; j < count; j++)
            if ((*(order+min))->value > (*(order+j))->value)
                min = j;

        if (i != min)
        {
            BOOK * ptemp = order[i];
            order[i] = order[min];
            order[min] = ptemp;
        }
    }
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