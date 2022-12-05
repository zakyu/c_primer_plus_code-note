#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 20
#define COLS 30

void generate_source(int row, int col);
void optimize_data(int rows, int cols, int data[rows][cols]);
void write_data(FILE * file, int rows, int cols, int data[rows][cols]);
int next_data(FILE * file);
void read_file(char *, int rows, int cols, int [rows][cols]);
void init_chars(int cols, char chars[ROWS][cols], int data[][COLS], int rows);
void output(char * filename, int cols, char chars[ROWS][cols]);

const char CHR_ARRAY[] = {' ', '.', '\'', '~', '*', '=', '&', '%', '#'};

int main(void)
{
    generate_source(ROWS, COLS);

    int data[ROWS][COLS];
    char chars[ROWS][COLS+1];

    // read source file to data
    read_file("source", ROWS, COLS, data);

    // init chars according to data
    init_chars(COLS+1, chars, data, ROWS);

    // output chars to file
    output("output", COLS+1, chars);

    return 0;
}

void generate_source(int row, int col)
{
    FILE * file;
    int data[row][col];

    srand(time(0));

    if((file = fopen("source", "w")) == NULL)
    {
        fprintf(stderr, "Can't open file: source\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            data[i][j] = rand()%10;
    }

    // optimize data
    optimize_data(ROWS, COLS, data);

    // write data into file
    write_data(file, ROWS, COLS, data);

    if (fclose(file)!=0)
    {
        fprintf(stderr, "Error in closing file.\n");
        exit(EXIT_FAILURE);
    }
}

void optimize_data(int rows, int cols, int data[rows][cols])
{
    const int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int total = 0, offset_count = 0, side_count = 0;

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            for (int i = 0; i < 4; i++)
            {
                int offset_x = x + offset[i][0];
                int offset_y = x + offset[i][1];

                if (offset_x < 0 || offset_x > rows 
                    || offset_y < 0 || offset_y > cols)
                    continue;

                side_count++;
                if (data[x][y] - data[offset_x][offset_y] > 1)
                {
                    offset_count++;
                    total += data[offset_x][offset_y];
                }
            }
            if (side_count == offset_count)
                data[x][y] = 1.0 * total / offset_count + 0.5;
        }
    }
}

void write_data(FILE * file, int rows, int cols, int data[rows][cols])
{
    if (file == NULL)
        return;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            fprintf(file, "%d ", data[i][j]);
        putc('\n', file);
    }
}

void read_file(char * filename, int rows, int cols, int data[rows][cols])
{
    FILE * source;
    if((source = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file: source\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0, ch; j < cols; j++)
        {
            data[i][j] = next_data(source);
        }
    }

    fclose(source);
}

int next_data(FILE * file)
{
    int ch;
    while ((ch = getc(file)) != EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            ch = ch-'0';
            break;
        }
    }
    return ch;
}

void init_chars(int cols, char chars[ROWS][cols], int data[][COLS], int rows)
{
    for (int i = 0; i < ROWS; i++)
    {
        int j;
        for (j = 0; j < cols-1; j++)
        {
            chars[i][j] = (char) CHR_ARRAY[data[i][j]];
        }
        chars[i][j] = '\0';
    }
}

void output(char * filename, int cols, char chars[ROWS][cols])
{
    FILE * output;
    if((output = fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "Can't open file: source\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ROWS; i++)
    {
        fprintf(output, "%s\n", chars[i]);
    }
    
    fclose(output);
}
