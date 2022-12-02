#include <stdio.h>

int main(void)
{
    int a, b;

    printf("输入上限和下限（如 5,1）：");
    scanf("%d,%d", &b, &a);
    for (;a<=b;a++) {
        printf("%10d%10d%10d\n", a, a*a, a*a*a);
    }

    return 0;
}
