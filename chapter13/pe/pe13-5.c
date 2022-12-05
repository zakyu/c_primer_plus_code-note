#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void append(FILE *, FILE *);

int main(int argc, char * argv[])
{
    FILE *ftarget, *fsource;
    int filenum = 0;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s targetfilename sourcefilename1 "
                        "sourcefilename2 ...\n", 
                    argv[0]);
        exit(EXIT_FAILURE);
    }

    char ch;

    // 目标文件
    if ((ftarget = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(ftarget, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fsource = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fsource, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                exit(EXIT_FAILURE);
            }
            append(ftarget, fsource);

            if (ferror(fsource) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
            if (ferror(ftarget) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[1]);

            if (fclose(fsource) != 0)
                fprintf(stderr, "Error closing file %s\n", argv[i]);

            filenum++;
            printf("File %s appended.\n", argv[i]);
        }
    }
    
    printf("Done appending. %d files appended.\n", filenum);
    rewind(ftarget);
    printf("%s contents:\n", argv[1]);
    while ((ch = getc(ftarget)) != EOF)
        putchar(ch);
    puts("Done displaying.");

    if (fclose(ftarget) != 0)
        fprintf(stderr, "Error closing file %s\n", argv[1]);
    return 0;
}

void append(FILE * target, FILE * source)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, target);
}