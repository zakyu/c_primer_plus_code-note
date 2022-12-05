#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pe13-13a.h"

#define ROWS 20
#define COLS 30

const char CHR_ARRAY[] = {' ', '.', '\'', '~', '*', '=', '&', '%', '#'};

void init_chars(int cols, char chars[ROWS][cols], int data[][COLS], int rows);
void output(char * filename, int cols, char chars[ROWS][cols]);

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