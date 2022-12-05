#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(void)
{
    double numbers[SIZE];
    double value;
    const char * file = "numbers.dat";
    FILE * iofile;
    int i;
    long pos;

    for (i = 0; i < SIZE; i++)
        numbers[i] = 100.0*i+1.0/(i+1);
    
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }

    fwrite(numbers, sizeof(double), SIZE, iofile);
    fclose(iofile);
    
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    printf("Enter an index in the range 0-%d.\n", SIZE-1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < SIZE)
    {
        pos = i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit): ");
    }
    
    puts("BYE.");

    fclose(iofile);
    return 0;
}