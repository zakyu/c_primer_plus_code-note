// 输入水的夸脱数，显示水分子的数量
// 1夸脱水大约950克，1个水分子的质量是3e-23
#include <stdio.h>

int main(void)
{
    int quart;

    scanf("%d", &quart);
    printf("%f\n", quart*950/3e-23);

    return 0;
}
