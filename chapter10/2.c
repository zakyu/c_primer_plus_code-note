#include <stdio.h>

#define SIZE 5

void copy_arr(double [], double [], int);
void copy_ptr(double *, double *, int);
void copy_ptrs(double *, double *, double *);
void print_arr(double [], int);

int main(void)
{
    double source[SIZE] = { 1, 2, 3, 4, 5 };
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source+5);
    print_arr(source, SIZE);
    print_arr(target1, SIZE);
    print_arr(target2, SIZE);
    print_arr(target3, SIZE);

    return 0;
}

void copy_arr(double target[], double source[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double * target, double * source, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        *(target + i) = *(source + i);
    }
}

void copy_ptrs(double * target, double * source, double * end)
{
    while(source < end)
    {
        *target = *source;
        target++;
        source++;
    }
}

void print_arr(double arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%f ", arr[i]);
    }
    putchar('\n');
}

