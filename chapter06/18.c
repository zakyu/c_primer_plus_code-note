#include <stdio.h>
#define DUNBAR 150

int main(void)
{
    const int start = 5;
    int count, n;
    
    for(count = start, n = 1; DUNBAR > count; n++) {
        count = (count-n)*2;
        printf("%10d%10d\n", count, n);
    }
    
    return 0;
}
