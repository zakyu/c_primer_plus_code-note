#include <stdio.h>

const int arr[] = { 1, 2, 4, 1, 3, 2, 6, 2 };

int max(const int [], int);

int main(void)
{
    printf("max %d\n", max(arr, 8));

    return 0;
}

int max(const int arr[], int size)
{
    int m = arr[0];
    int i;
    for(i = 1; i < size; i++)
    {
        if(m < arr[i])
            m = arr[i];
    }
    return m;
}
