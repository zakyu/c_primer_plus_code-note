#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 256

char * s_gets(char * st, int size);
long count(char ch, char * string);

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s char [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        char string[SLEN];
        printf("Enter strings (ctrl+d to quit): \n");
        s_gets(string, SLEN);
        printf("character %c appeared %ld times in string.\n",
                    argv[1][0], count(argv[1][0], string));
        exit(EXIT_SUCCESS);
    }

    FILE * file;
    for (int i = 2; i < argc; i++)
    {
        if ((file = fopen(argv[i], "r")) == NULL)
        {
            printf("Fail to open file %s\n", argv[i]);
            continue;
        }

        long total = 0; 
        char ch;
        while ((ch = getc(file)) != EOF)
        {
            if (ch == argv[1][0])
                total++;
        }
        printf("character %c appeared %ld times in file %s.\n",
                    argv[1][0], total, argv[i]);
        fclose(file);
    }

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

long count(char ch, char * string)
{
    long total = 0;

    while(*string != EOF)
    {
        if (*string == ch)
            total++;
        string++;
    }

    return total;
}