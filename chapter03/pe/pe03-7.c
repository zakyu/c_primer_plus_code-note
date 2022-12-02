// 输入身高（英寸），以厘米为单位显示身高
#include <stdio.h>

int main(void)
{
    int height;

    scanf("%d", &height);
    printf("%f", height * 2.54);

    return 0;
}
