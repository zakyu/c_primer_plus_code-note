#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(FILE * target, FILE * source);

int main(int argc, char * argv[])
{
    FILE * sourcefile, * targetfile;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s SourceFileName CopyFileName\n",
                    argv[0]);
        exit(EXIT_FAILURE);
    }

    // open source file
    if ((sourcefile = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // open target file
    if ((targetfile = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // copy
    copy(targetfile, sourcefile);

    // close
    fclose(targetfile);
    fclose(sourcefile);
    return 0;
}

void copy(FILE * target, FILE * source)
{
    size_t bytes;
    static char * temp[BUFSIZ];
    while ((bytes = fread(temp, sizeof(char), BUFSIZ, source)))
        fwrite(temp, sizeof(char), BUFSIZ, target);
}