#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

static int times[10] = {0};

void generate(int count);
void print_array(int * array, int size);

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("#%d generate:\n", i+1);
        generate(1000);
        print_array(times, 10);
    }

    return 0;
}

void generate(int count)
{
    unsigned seed = (unsigned)time(0);
    printf("seed = %u\n", seed);
    srand(seed);
    for (int i = 0; i < count; i++)
    {
        times[(rand() % 10)]++;
    }
    sleep(1);
}

void print_array(int * array, int size)
{
    for (int i = 0; i < size; i++)
        printf("#%02d: %d\n", i, array[i]);
}