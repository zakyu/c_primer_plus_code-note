#include <stdio.h>

#define ROWS 3
#define COLS 5

void input(double [][COLS], int);
void print(const double [][COLS], int);
void average_rows(const double array[][COLS], int rows);
double average_row(const double arr[], int size);
double average(const double array[][COLS], int rows);
double max(const double array[][COLS], int rows);

int main(void)
{
    double array[ROWS][COLS];
    
    input(array, ROWS);
    average_rows(array, ROWS);
    int i;
    for (i = 0; i < ROWS; i++)
    {
        printf("Row %d average is %.2f\n", i+1, average_row(array[i], COLS));
    }
    printf("Average is %.2f\n", average(array, ROWS));
    printf("Max is %.2f\n", max(array, ROWS));

    return 0;
}

void input(double array[][COLS], int rows)
{
    int r, c;

    printf("输入3组数，每组数包含5个double类型的数:\n");
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            scanf("%lf", &array[r][c]);
}

void print(const double array[][COLS], int rows)
{
    int r, c;
    for (r = 0; r < rows; r++)
    { 
        for(c = 0; c < COLS; c++)
            printf("%.1f ", array[r][c]);
        printf("\n");
    }
}

void average_rows(const double array[][COLS], int rows)
{
    int r, c;
    double sum, ave;
    for (r = 0; r < rows; r++)
    {
        sum = 0;
        for (c = 0; c < COLS; c++)
            sum += array[r][c];
        ave = sum / COLS;
        printf("average #%d: %.2f\n", r, ave);
    }
}

double average_row(const double arr[], int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}

double average(const double array[][COLS], int rows)
{
    int r, c;
    double sum, ave;
    sum = 0;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            sum += array[r][c];
    
    ave = sum / (rows*COLS);
    return ave;
}

double max(const double array[][COLS], int rows)
{
    int r, c;
    double max = array[0][0];
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            if (max < array[r][c])
                max = array[r][c];
    return max;
}
