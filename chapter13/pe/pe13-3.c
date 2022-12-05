#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 81

int main(void)
{
    char filename[SIZE];
    FILE * file;
    int ch;

    printf("Enter filename: ");
    scanf("%s", filename);

    if ((file = fopen(filename, "rw+")) == NULL)
    {
        fprintf(stderr, "Fail to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(file)) != EOF)
    {
        if (islower(ch))
        {
            fseek(file, -1, SEEK_CUR);
            ch = toupper(ch);
            fputc(ch, file);
        }
    }
    
    fclose(file);

    return 0;
}
