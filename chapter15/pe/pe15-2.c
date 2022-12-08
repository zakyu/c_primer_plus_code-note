#include <stdio.h>
#include <limits.h>

int bstoi(char * bstr);
char* itobs(int number, char* bit_str);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <binary1> <binary2>\n", argv[0]);
        return 1;
    }

    int b1 = bstoi(argv[1]);
    int b2 = bstoi(argv[2]);

    char bin_str[CHAR_BIT*sizeof(int)+1];

    printf("~%s = %s\n", argv[1], itobs(~b1, bin_str));
    printf("~%s = %s\n", argv[2], itobs(~b2, bin_str));
    printf("%s | %s = %s\n", argv[1], argv[2], itobs(b1|b2, bin_str));
    printf("%s & %s = %s\n", argv[1], argv[2], itobs(b1&b2, bin_str));
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(b1^b2, bin_str));

    return 0;
}

int bstoi(char * bstr)
{
    int result = 0;

    while (*bstr)
    {
        result <<= 1;
        result |= *bstr-'0';
        bstr++;
    }
    return result;
}

char* itobs(int number, char* bit_str)
{
    int i;
    const static int size = CHAR_BIT*sizeof(int);

    for (i = size-1; i >= 0 ; i--, number >>= 1)
        bit_str[i] = (01 & number) + '0';
    bit_str[size] = '\0';
    return bit_str;
}