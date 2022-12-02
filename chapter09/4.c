#include <stdio.h>

double harmonic(double, double);

int main(void)
{
    printf("%f\n",harmonic(2, 1));

    return 0;
}

double harmonic(double x, double y) {
    return 2/(1/x+1/y);
}
