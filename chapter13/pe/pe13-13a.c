#include "pe13-13a.h"

int next_data(FILE * file);

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