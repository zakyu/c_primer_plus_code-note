#include <stdio.h>
#include <stdlib.h>

#define SLEN 41

void print(FILE * file, long pos);
char * s_gets(char * st, int size);

int main(void)
{
    FILE * file;
    char filename[SLEN];
    long pos;

    puts("Enter filename:");
    s_gets(filename, SLEN);

    if ((file = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    puts("Enter a position in file (negative number/ not a number to quit):");
    while((scanf("%ld", &pos) == 1) && pos >= 0)
    {
        print(file, pos);
        puts("Enter a position in file (-1 or q to quit):");
    }

    fclose(file);
    return 0;
}

void print(FILE * file, long pos)
{
    int ch;
    fseek(file, pos, SEEK_SET);
    while((ch = getc(file)) != EOF && ch != '\n')
        putc(ch, stdout);
    putchar('\n');
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