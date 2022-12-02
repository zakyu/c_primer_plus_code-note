#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    chline('A', 5, 3);

    return 0;
}

void chline(char ch, int i, int j) {
    for(;i>0;i--) {
        for(int k = j;k>0;k--)
            putchar(ch);
        putchar('\n');
    }
}
