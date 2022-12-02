#include <stdio.h>
#include <float.h>

int main(void)
{
    double num1 = 1.0/3.0;
    float num2 = 1.0/3.0;
    printf("%20.6f %20.6f\n", num1, num2);
    printf("%20.12f %20.12f\n", num1, num2); 
    printf("%20.16f %20.16f\n", num1, num2);

    printf("FLT_DIG: %d\n", FLT_DIG);
    printf("DBL_DIG: %d\n", DBL_DIG);

    return 0;
}
