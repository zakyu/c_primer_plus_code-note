#include <stdio.h>

int main(void)
{
    double a, b;

    printf("输入两个浮点数（非数字退出）：");
    while(scanf("%lf %lf", &a, &b)) {
        printf("%f\n", func(a, b));
        printf("输入两个浮点数（非数字退出）：");
    }


    return 0;
}

double func(double a, double b){
    return (a-b)*(a+b);
}
