#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

void generate(int * array, int count);
void sort(int * array, int size);
void swap(int * array, int x, int y);
void print_array(int * array, int size);

int main(void)
{
    int randnums[SIZE];

    generate(randnums, SIZE);
    print_array(randnums, SIZE);
    sort(randnums, SIZE);
    print_array(randnums, SIZE);

    return 0;
}

void generate(int * array, int count)
{
    srand((unsigned)time(0));
    for (int i = 0; i < count; i++)
    {
        array[i] = (rand() % 10) + 1;
    }
}

void sort(int * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int max_index = i;
        for (int j = i+1; j < size; j++)
        {
            if (array[max_index] < array[j])
                max_index = j;
        }
        if (i != max_index)
            swap(array, i, max_index);
    }    
}

void swap(int * array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void print_array(int * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%2d ", array[i]);
        if ((i+1) % 10 == 0)
        {
            putchar('\n');
        }
    }
    putchar('\n');
}