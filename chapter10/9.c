#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy(int, int, double[*][*], double[*][*]);
void show(int, int, double[*][*]);

int main(void)
{
    double source[ROWS][COLS] = {
        { 1, 2, 3, 4, 5 },
        { 2, 3, 4, 5, 6 },
        { 3, 4, 5, 6, 7 }
    };
    double target[ROWS][COLS];

    show(ROWS, COLS, source);
    copy(ROWS, COLS, target, source);

    show(ROWS, COLS, target);

    return 0;
}

void copy(int n, int m, double target[n][m], double source[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            target[i][j] = source[i][j];
}

void show(int n, int m, double arr[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%.1f ", arr[i][j]);
        printf("\n");
    }
}
