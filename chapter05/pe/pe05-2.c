#include <stdio.h>

int main(void)
{
    int num;
    printf("输入一个整数：");
    scanf("%d", &num);
    
    int i = -1;
    while(i++ < 10) {
        printf("%d ", num+i);
    }
    printf("\n");

    return 0;
}
