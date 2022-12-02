#include <stdio.h>

#define SIZE 5
void add_arrs(int [], int [], int [], int);

int main(void)
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 2, 3, 4, 5, 6 };
    int sum[SIZE];

    add_arrs(arr1, arr2, sum, SIZE);
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", sum[i]);
    }
    printf("\n");

    return 0;
}

void add_arrs(int arr1[], int arr2[], int sum[], int size)
{
    for (int i = 0; i < size; i++)
    {
        sum[i] = arr1[i] + arr2[i];
    }

}
