#include <stdio.h>

void input(char st[], int n);

int main(void)
{
    char st[40];

    input(st, 3);
    puts(st);

    return 0;
}

void input(char st[], int n)
{
    int ct = 0, in = 0;
    char temp;

    while(ct < n)
    {
        temp = getchar();
        if (temp == ' ' || temp == '\n' || temp == '\0' || temp == '\t')
            if (in)
                break;
            else
                continue;

        st[ct++] = temp;
        in = 1;
    }
}
