#include <stdio.h>

void to_base_n(int num, int n);

int main(void)
{
    to_base_n(255, 2); 
    putchar('\n');
    return 0;
}

void to_base_n(int num, int n)
{
    int r;

    r = num%n;
    if (num >= n)
        to_base_n(num/n, n);
    printf("%d", r);
}
