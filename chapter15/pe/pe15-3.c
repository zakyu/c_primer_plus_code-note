#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int active_count(int number);

int main(void)
{
    printf("Active count of %d is %d\n", 255, active_count(255));

    return 0;
}

int active_count(int number)
{
    const static int size = CHAR_BIT*sizeof(int);
    char * binary = malloc(size+1);
    int count = 0;

    for (int i = size-1; i >= 0 ; i--, number >>= 1)
        binary[i] = (01 & number) + '0';
    binary[size] = '\0';

    while (*binary)
        if (*binary++ == '1')
            count++;

    return count;
}