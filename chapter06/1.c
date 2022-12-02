#include <stdio.h>

#define SIZE 26

int main(void)
{
    char letters[SIZE];
    int index;
    for(index=0; index<SIZE; index++){
        letters[index] = 'a' + index;
    }

    for(index=0; index<SIZE; index++){
        printf("%c ", letters[index]);
    }
    printf("\n");
       

    return 0;
}
