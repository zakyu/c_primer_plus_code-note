#include <stdio.h>

void copy(int [], int *, int);

int main(void)
{
    int source[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int target[3];

    copy(target, source+2, 3);
    for (int i = 0; i < 3; i++)
        printf("%d\n", target[i]);

    return 0;
}

void copy(int target[], int * start, int num)
{
    int i;
    for(i = 0; i < num; i++)
        target[i] = *(start+i);
}
