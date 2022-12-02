#include <stdio.h>

const int arr[] = { 1, 2, 4, 1, 3, 2, 6, 2 };

int max_index(const int [], int);

int main(void)
{
    printf("max index %d\n", max_index(arr, 8));

    return 0;
}

int max_index(const int arr[], int size)
{
    int m = arr[0];
    int m_index = 0;
    int i;
    for(i = 1; i < size; i++)
    {
        if(m < arr[i])
        {
            m = arr[i];
            m_index = i;
        }
    }
    return m_index;
}
