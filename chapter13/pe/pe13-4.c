#include <stdio.h>
#include <stdlib.h>

void print_file(FILE * file);

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename1 filename2 ... \n",
                     argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE * file;
    for (int i = 1; i < argc; i++)
    {
        if ((file = fopen(argv[i], "r")) == NULL)
        {
            printf("Fail to open file %s.\n", argv[i]);
            continue;
        }
        printf("file %s: \n", argv[i]);
        print_file(file);
        putchar('\n');
        fclose(file);
    }

    return 0;
}

void print_file(FILE * file)
{
    int ch;
    while ((ch = getc(file)) != EOF)
        putc(ch, stdout);
}