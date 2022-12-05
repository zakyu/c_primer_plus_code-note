#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int line_count(FILE * file);

int main(void)
{
    FILE * file;
    char words[MAX];
    int line;

    if ((file = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    line = line_count(file);

    puts("Enter words to add to the file; "
    "press the # key at the beginning of a line to terminate.");

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0]) != '#')
        fprintf(file, "%d %s\n", line++, words);
    
    puts("File contents:");
    rewind(file);
    while(fscanf(file, "%*s %s", words) == 1)
        puts(words);

    puts("Done.");

    if (fclose(file) != 0)
        fprintf(stderr, "Error closing file\n");
        
    return 0;
}

int line_count(FILE * file)
{
    int line = 1;
    
    int ch;
    while ((ch = getc(file)) != EOF)
    {
        if (ch == '\n')
            line++;
    }
    rewind(file);
    return line;
}