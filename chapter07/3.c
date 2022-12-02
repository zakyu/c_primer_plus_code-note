#include <stdio.h>

int main(void)
{
    int num, o_ct = 0, e_ct = 0;
    float o_sum, e_sum;

    scanf("%d", &num);
    while(num != 0) {
        if (num%2 != 0) {
            o_ct++;
            o_sum += num;
        } else {
            e_ct++;
            e_sum += num;
        }
        scanf("%d", &num);
    }
    printf("o_ct: %d, o_ave: %f, e_ct: %d, e_ave: %f\n",
                o_ct, o_sum/o_ct, e_ct, e_sum/e_ct);
    
    return 0;
}
