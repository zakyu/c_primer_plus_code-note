#include <stdio.h>
#define ROWS 2
#define COLS 5

void copy_arr(double [][COLS], double [][COLS], int);
void print_arr(double [][COLS], int);

int main(void)
{
    double source[ROWS][COLS] = { { 2, 3, 4, 5, 6 }, { 1, 2, 3, 4, 5 } };
    double target[ROWS][COLS];
    
    copy_arr(target, source, ROWS);
    print_arr(target, ROWS);

    return 0;
}

void copy_arr(double target[][COLS], double source[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            target[r][c] = source[r][c];
}

void print_arr(double arr[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < COLS; c++)
            printf("%.1f ", arr[r][c]);
        putchar('\n');
    }
}
