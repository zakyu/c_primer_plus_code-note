// 倒序显示文件内容
#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'
#define SIZE 81

int main(void)
{
    char file[SIZE];
    char ch;
    FILE * fp;
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    last = ftell(fp);
    for (count = 1; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r')
            putchar(ch);
    }
    putchar('\n');
    
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file.\n");
    return 0;
}