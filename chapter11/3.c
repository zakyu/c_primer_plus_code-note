#include <stdio.h>

void input(char st[]);

int main(void)
{
    char st[40];

    input(st);
    puts(st);

    return 0;
}

void input(char st[])
{
    scanf("%s", st);
}
