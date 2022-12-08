#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char * itobs(unsigned number, char * bin_str);
unsigned rotate_left(unsigned number, int times);

int main(void)
{
    printf("%u rotate left %d = %u\n", 8, 1, rotate_left(8, 2));

    return 0;
}

unsigned rotate_left(unsigned number, int times)
{
    char * bin_str = malloc(CHAR_BIT*sizeof(int)+1);
    const static int size = CHAR_BIT*sizeof(int);
    for (int i = size - times; i >= 0; i--)
    {
        bin_str[i] = (1&number)+'0';
        number >>= 1;
    }
    for(int i = 0; i < times; i++)
    {
        bin_str[size-1-i] = (1&number)+'0';
        number >>= 1;
    }
    bin_str[size] = '\0';

    int result = 0;
    while (*bin_str)
    {
        result |= *bin_str=='1';
        result <<= 1;
        bin_str++;
    }
    return result;
}