#include <stdio.h>

void Temperatures(double);

int main(void)
{
    double fahrenheit;
    int result;

    printf("输入一个华氏温度： ");
    result = scanf("%lf", &fahrenheit);
    while(result > 0) {
        Temperatures(fahrenheit);

        printf("输入一个华氏温度： ");
        result = scanf("%lf", &fahrenheit);
    }
    return 0;
}

void Temperatures(double f)
{
    double c, k;
    c = 5.0/9.0*(f - 32.0);
    k = c + 273.16;

    printf("Fahrenheit: %.2f, Celsius: %.2f, Kelvin: %.2f\n",
                f, c, k);
    
    return;
}

