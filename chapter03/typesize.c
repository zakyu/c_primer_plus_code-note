#include <stdio.h>

int main(void)
{
    printf("int: %zd\n", sizeof(int));
    printf("char: %zd\n", sizeof(char));
    printf("short: %zd\n", sizeof(short));
    printf("long: %zd\n", sizeof(long));
    printf("long long: %zd\n", sizeof(long long));
    printf("double: %zd\n", sizeof(double));
    printf("long double: %zd\n", sizeof(long double));
    printf("float: %zd\n", sizeof(float));
    
    return 0;
}
