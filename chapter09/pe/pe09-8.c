#include <stdio.h>
#include <stdlib.h>

double power(double, int);
double fun(double, int);

int main(void)
{
    printf("%f\n", power(5, -3));

    return 0;
}

double power(double n, int p)
{
    if (n == 0 || p == 0) {
        printf("undefined!\n");
        return 1;
    }
    if (n==0) {
        return 0;
    }
    if (p==0) {
        return 1;
    }

    double result = fun(n, abs(p));
    if (p < 0)
        return 1/result;
    return result;
}

double fun(double n, int p)
{
    double result = 1;
    int i, j;
    for(i=p;i>0;i--) {
        result *= n;
    }
    return result;
}

