#include <stdio.h>
#include <stdlib.h>

#define SLEN 256

void print_line(FILE * file, int filenum);

int status; 

int main(int argc, char * argv[])
{
    FILE * file1, * file2;
    char line[SLEN];

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Fail to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Fail to open file %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int i = 1;
    while (status < 3)
    {
        printf("#%d\t", i);
        if (status == 1)
        {
            print_line(file2, 2);
        }
        else if (status == 2)
        {
            print_line(file1, 1);
        }
        else
        {
            print_line(file1, 1);
            print_line(file2, 2);
        }
        i++;
        putchar('\n');
    }

    
    if (fclose(file1) != 0 || fclose(file2) != 0)
    {
        fprintf(stderr, "Erorr in closing files.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void print_line(FILE * file, int filenum)
{
    int ch;
    while ((ch = getc(file)) != EOF)
    {        
        if (ch == '\n')
        return;
        putc(ch, stdout);
    }

    status |= filenum;
}