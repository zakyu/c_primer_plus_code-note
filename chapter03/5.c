#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int8_t age;

    printf("your age is: ");
    scanf("%" SCNd8, &age);
    printf("%.0lf\n",age*3.156e7);

    return 0;
}
