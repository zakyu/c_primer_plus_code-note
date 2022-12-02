#include <stdio.h>

int main(void)
{
    char ch;
    int s_ct = 0, r_ct = 0, o_ct = 0;
    
    while((ch=getchar()) != '#') {
        switch(ch) {
            case ' ': s_ct++; break;
            case '\n': r_ct++; break;
            default: o_ct++;
        }
    }

    printf("s_ct: %d, r_ct: %d, o_ct: %d \n",
                s_ct, r_ct, o_ct);


    return 0;
}
