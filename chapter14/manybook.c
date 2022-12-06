#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int size);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    puts("Please enter the book title.");
    puts("Press [enter] at the start of a line to stop.\n");

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
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);
        }
    }
    else
        puts("No books? Too bad.");

    return 0;
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