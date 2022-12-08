#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const static int size = CHAR_BIT*sizeof(int);

char * itobs(int number, char * binary_str);
int get_val(int number, int pos);

int main(void)
{
    printf("%d->%d = %d\n", 8, 4, get_val(8, 4));

    return 0;
}

int get_val(int number, int pos)
{
    char * bin_str = malloc(size+1);
    itobs(number, bin_str);
    puts(bin_str);
    return bin_str[size-pos]=='1'?1:0;
}

char * itobs(int number, char * binary_str)
{
    for(int i = size-1; i >= 0; i--)
    {
        binary_str[i] = (1&number) + '0';
        number >>= 1;
    }
    binary_str[size] = '\0';
    return binary_str;
}