#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81
#define BUFSIZE 4096

char * s_gets(char * st, int size);
void append(FILE *, FILE *);

int main(void)
{
    FILE *ftarget, *fsource;
    int filenum = 0;

    char tar_name[SLEN];
    char src_name[SLEN];

    char ch;

    // 目标文件
    puts("Enter name of destination file:");
    s_gets(tar_name, SLEN);
    if ((ftarget = fopen(tar_name, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", tar_name);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(ftarget, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    // 内容文件
    puts("Enter name of first source file (empty line to quit):");
    while (s_gets(src_name, SLEN) && src_name[0] != '\0')
    {
        if (strcmp(src_name, tar_name) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fsource = fopen(src_name, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", src_name);
        else
        {
            if (setvbuf(fsource, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                exit(EXIT_FAILURE);
            }
            append(ftarget, fsource);

            if (ferror(fsource) != 0)
                fprintf(stderr, "Error in reading file %s.\n", src_name);
            if (ferror(ftarget) != 0)
                fprintf(stderr, "Error in writing file %s.\n", tar_name);

            if (fclose(fsource) != 0)
                fprintf(stderr, "Error closing file %s\n", src_name);

            filenum++;
            printf("File %s appended.\n", src_name);
            puts("Next file (empty lien to quit):");
        }
    }
    
    printf("Done appending. %d files appended.\n", filenum);
    rewind(ftarget);
    printf("%s contents:\n", tar_name);
    while ((ch = getc(ftarget)) != EOF)
        putchar(ch);
    puts("Done displaying.");

    if (fclose(ftarget) != 0)
        fprintf(stderr, "Error closing file %s\n", tar_name);
    return 0;
}

void append(FILE * target, FILE * source)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, target);
}

char * s_gets(char * st, int size)
{
    char * ret;
    ret = fgets(st, size, stdin);
    if (ret)
    {
        int i = 0;
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret;
}