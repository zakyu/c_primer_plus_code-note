#include <stdio.h>

char * search(char * str, char ch);

int main(void)
{
    char st[] = "words";
    char ch = 's';
    char ch2 = 'q';

    char * result1 = search(st, ch2);
    if (result1)
    {
        printf("result1 = %p, *result1 = %c", result1, *result1);
    }
    else
        puts("没有 's' ");



    return 0;
}

char * search(char * str, char ch)
{
    char * index = NULL;

    while(*str)
    {
        if (*str == ch)
        {
            index = str;
            break;
        }

        str++;
    }

    return index;
}
