#include <stdio.h>

int main(void)
{
    char firstname[20];
    char lastname[20];

    printf("输入名和姓：");
    scanf("%s %s", firstname, lastname);
    printf("%s,%s\n", firstname, lastname);

    return 0;
}
