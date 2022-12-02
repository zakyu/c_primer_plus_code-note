#include <stdio.h>

int SumOfSquares(int lower, int upper);

int main(void)
{
    int upper, lower;
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);

    while(lower<upper) {
        printf("The sums of the squares from %d to %d is %d.\n",
                lower, upper, SumOfSquares(lower, upper));
        
        printf("Enter lower and upper integer limits: ");
        scanf("%d %d", &lower, &upper);
    }
    return 0;
}

int SumOfSquares(int lower, int upper) {
    int sum = 0;
    int i;
    for(i = lower; i <= upper; i++) {
        sum += i*i;
    }

    return sum;
}
