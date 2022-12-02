#include <stdio.h>

void cube(double);

int main(void)
{
    double num;

    printf("输入一个DOUBLE值：");
    scanf("%lf", &num);
    
    cube(num);
    
    return 0;
}

void cube(double num) 
{
    printf("%f\n",num*num*num);
}
