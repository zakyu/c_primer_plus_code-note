#include <stdio.h>

int main(void)
{
    float height;
    char name[40];

    printf("输入身高（单位：英寸）和姓名：");
    scanf("%f %s", &height, name);
    
    printf("%s, %f", name, height);

    return 0;
}
