#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 256

void search_print(char * string, FILE * file);

int main(int argc, char * argv[])
{
    FILE * file;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s string file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    search_print(argv[1], file);

    if (fclose(file) != 0)
    {
        fprintf(stderr, "Error in closing file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    return 0;
}

void search_print(char * string, FILE * file)
{
    char line[SLEN];
    while (fgets(line, SLEN, file))
    {    
        char * find;
        if(find = strstr(line, string))
            printf("%s", line);
    }
}