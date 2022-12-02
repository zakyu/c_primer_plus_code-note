#include <stdio.h>

int f(int);

int main(void)
{
    printf("%d\n", f(8));
    
    return 0;
}

int f(int n) {
    if(n == 0)
        return 0;
    if(n < 3)
        return 1;
    return f(n-1) + f(n-2);
}
