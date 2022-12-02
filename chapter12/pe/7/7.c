#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

void print_array(const int * array, int size);

int main(void)
{
    int sets, sides, dice;

    srand((unsigned)time(0));

    printf("Enter the number of sets; enter q to stop : ");
    while (scanf("%d", &sets))
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        int nums[sets];
        for (int i = 0; i < sets; i++)
        {
            nums[i] = roll_n_dice(dice, sides);
        }

        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        print_array(nums, sets);

        printf("How many sets? Enter q to stop: ");
        scanf("%d", &sets);
    }

    puts("Bye!");
    return 0;
}

void print_array(const int * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
        if ((i+1)%15 == 0)
        putchar('\n');
    }
    putchar('\n');
}