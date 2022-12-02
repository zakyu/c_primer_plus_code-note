#include <stdio.h>

void critic(int * units);

int main(void)
{
    int number;
    int * units;
    units = &number;

    puts("How many pounds to a firkin of butter?");
    scanf("%d", units);
    while (*units != 56)
        critic(units);

    puts("You must have looked it up!");

    return 0;
}

void critic(int * units)
{
    puts("No luck, my friend. Try again.");
    scanf("%d", units);
}
