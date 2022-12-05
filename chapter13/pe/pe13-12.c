#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 20
#define COLS 30

void generate_source(int row, int col);
int next_data(FILE * file);
void read_file(char *, int [ROWS][COLS]);
void init_chars(char chars[ROWS][COLS+1], int data[ROWS][COLS]);
void output(char * filename, char chars[ROWS][COLS+1]);

const char CHR_ARRAY[] = {' ', '.', '\'', '~', '*', '=', '&', '%', '#'};

int main(void)
{
    generate_source(ROWS, COLS);

    int data[ROWS][COLS];
    char chars[ROWS][COLS+1];

    // read source file to data
    read_file("source", data);

    // init chars according to data
    init_chars(chars, data);

    // output chars to file
    output("output", chars);

    return 0;
}

void generate_source(int row, int col)
{
    FILE * file;

    srand(time(0));

    if((file = fopen("source", "w")) == NULL)
    {
        fprintf(stderr, "Can't open file: source\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fprintf(file, "%d ", rand()%10);
        }
        putc('\n', file);
    }

    if (fclose(file)!=0)
    {
        fprintf(stderr, "Error in closing file.\n");
        exit(EXIT_FAILURE);
    }
}

void read_file(char * filename, int data[ROWS][COLS])
{
    FILE * source;
    if((source = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file: source\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0, ch; j < COLS; j++)
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

void init_chars(char chars[ROWS][COLS+1], int data[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        int j;
        for (j = 0; j < COLS; j++)
        {
            chars[i][j] = (char) CHR_ARRAY[data[i][j]];
        }
        chars[i][j] = '\0';
    }
    
}

void output(char * filename, char chars[ROWS][COLS+1])
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
