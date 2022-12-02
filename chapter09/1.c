#include <stdio.h>

double min(double, double);

int main(void)
{
    double x = 1.2, y = 2.4;

    printf("x=%f,y=%f,min=%f.\n", x, y, min(x,y));
    
    return 0;
}

double min(double x, double y) {
    return x<y?x:y;
}
