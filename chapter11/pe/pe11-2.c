#include <stdio.h>

void input(char *st, int n);

int main(void)
{   
    char ch[10];

    input(ch, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%c", ch[i]);
    }

    return 0;
}

void input(char * st, int n)
{
    int i = 0;
    char temp;
    while (temp=getchar(), temp!='\n' && temp!='\t' && temp != '\0' && i < n)
    {
        *(st+i) = temp;
        i++;
    }
}
