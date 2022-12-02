#include <stdio.h>

#define SIZE 5

double difference(double arr[], int size);

int main(void)
{
    double arr[SIZE] = { -11, 2, 5, 11, 55 };
    printf("difference %f \n", difference(arr, SIZE));
    return 0;
}

double difference(double arr[], int size)
{
    double max = arr[0], min = arr[0];
    int i;
    for (i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    return max-min;
}
