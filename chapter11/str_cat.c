#include <stdio.h>
#include <string.h>
#define SIZE 80

char * s_gets(char *, int);

int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";

    puts("What is your favrite flower?");
    if (s_gets(flower, SIZE))
    {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("bye");
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * result;
    int i = 0;
    result = fgets(st, n, stdin);
    if (result)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return result;
}
