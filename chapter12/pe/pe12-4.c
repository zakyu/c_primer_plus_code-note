#include <stdio.h>

int call_count();

static int count;

int main(void)
{
    while(1)
        printf("function called: %010d.\n", call_count());
    
    return 0;
}

int call_count()
{
    count++;
    return count;
}