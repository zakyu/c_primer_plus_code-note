#include <stdio.h>

void min(double*, double*, double*);
void interchange(double*, double*);

int main(void)
{
    double x=5, y=1, z=3;
    min(&x, &y, &z);
    printf("x=%f,y=%f,z=%f\n", x, y, z);
    
    return 0;
}

void min(double *x, double *y, double *z)
{
    if(*x > *y || *x > *z) {
        if(*y > *z)
            interchange(x, z);
        else
            interchange(x, y);
    }
    if(*y > *z) {
        interchange(y,z);
    }
}

void interchange(double *u, double *v)
{
    double temp;
    temp = *u;
    *u = *v;
    *v = temp;
}
