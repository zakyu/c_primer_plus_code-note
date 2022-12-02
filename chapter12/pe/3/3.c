#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
    int mode = 0;
    double distance, consumed_fuel;

    int m;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &m);
    while (m >= 0)
    {
        set_mode(&mode, m);
        get_info(mode, &distance, &consumed_fuel);
        show_info(mode, &distance, &consumed_fuel);
        printf("Enter 0 for metric mode, 1 for US mode(-1 to quit): ");
        scanf("%d", &m);
    }
    puts("Done.");

    return 0;
}
