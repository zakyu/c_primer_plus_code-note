#include <stdio.h>

int main(void)
{
    int age;
    int days;

    printf("input your age: ");
    scanf("%d", &age);
    days = age * 365;
    printf("your days is %d\n", days);

    return 0;
}
