#include <stdio.h>

int bstoi(char * bstr);

int main(void)
{
    char * pbin = "01001001";
    printf("%s = %d", pbin, bstoi(pbin));
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