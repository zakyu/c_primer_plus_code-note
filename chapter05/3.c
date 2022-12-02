#include <stdio.h>

int main(void)
{
    int days;
    printf("输入天数： ");
    scanf("%d", &days);

    while(days > 0) {
        printf("%d天是%d周%d天\n", days, days/7, days%7);
        
        printf("输入天数： ");
        scanf("%d", &days);
    }
    return 0;
}
