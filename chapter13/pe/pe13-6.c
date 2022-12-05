#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

char * s_gets(char * st, int size);

int main(void)
{
    FILE * in, * out;
    int ch;
    char name[LEN];
    int count = 0;

    char filename[LEN];
    printf("Enter file name: ");
    s_gets(filename, LEN);

    if ((in = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                filename);
        exit(EXIT_FAILURE);
    }

    strncpy(name, filename, LEN-5);
    name[LEN-5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
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