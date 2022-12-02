#include <stdio.h>

void show_arr(int [][5], int rows);
void show_arrx2(int [][5], int rows);

int main(void)
{
    int arr[3][5] = {
        { 1, 2, 3, 4, 5 },
        { 2, 3, 4, 5, 6 },
        { 4, 5, 6, 7, 8 },
    };
    
    show_arr(arr, 3);
    show_arrx2(arr, 3);

    return 0;
}

void show_arr(int arr[][5], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < 5; c++)
            printf("%d ", arr[r][c]);
        printf("\n");
    }
}

void show_arrx2(int arr[][5], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < 5; c++)
            printf("%d ", arr[r][c]*2);
        printf("\n");
    }
}
