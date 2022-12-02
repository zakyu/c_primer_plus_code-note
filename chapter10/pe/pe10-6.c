#include <stdio.h>

#define SIZE 5

void print_arr(double arr[], int size);
void sort(double arr[], int size);
void swap(double arr[], int i, int j);

int main(void)
{
    double arr[SIZE] = { 4, 2, 6, 1, 4};

    print_arr(arr, SIZE);
    sort(arr, SIZE);
    print_arr(arr, SIZE);

    return 0;
}

void print_arr(double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%f ", arr[i]);
    putchar('\n');
}

void sort(double arr[], int size)
{
    int max;
    int i, j;
    for (i = 0; i < size; i++)
    {
        max = i;
        for (j = i+1; j < size; j++)
        {
            if(arr[max] < arr[j])
                max = j;
        }
        if (i != max)
            swap(arr, i, max);
    }
}

void swap(double arr[], int i, int j)
{
    double temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
