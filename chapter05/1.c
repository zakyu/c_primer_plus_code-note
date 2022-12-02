#include <stdio.h>

#define M_H 60

int main(void)
{
    int minute;
    
    printf("输入分钟数（<=0退出）：");
    scanf("%d", &minute);
    
    while(minute > 0) {
        printf("%02d:%02d\n", minute / M_H, minute % M_H);
        
        printf("输入分钟数（<=0退出）：");
        scanf("%d", &minute);
    }

    return 0;
}
