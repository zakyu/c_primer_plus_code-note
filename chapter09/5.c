#include <stdio.h>

void larger_of(double *, double *);

int main(void)
{

    double x = 5, y = 8;
    larger_of(&x, &y);
    printf("x:%f, y:%f\n", x, y);
    return 0;
}

void larger_of(double * x, double * y)
{
    if(*x > *y) {
        *y = *x;
        return;
    }
    *x = *y;
}
