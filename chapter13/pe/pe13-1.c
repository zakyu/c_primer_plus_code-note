#include <stdio.h>
#include <stdlib.h>

#define LEN 40

int main(void)
{
    int ch;
    FILE * fp;
    unsigned long count = 0;
    char name[LEN];

    puts("Enter the name of the file to be processed:");
    scanf("%40s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", name, count);
    return 0;
}