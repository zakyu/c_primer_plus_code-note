#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func();

int main(void)
{
    func();

    return 0;
}

void func()
{
    int count;
    printf("How many words do you wish to enter? ");
    scanf("%d", &count);
    printf("Enter %d words now:\n", count);
    
    char * words[count];
    char * temp = (char *) malloc(256 * sizeof(char));
    for (int i = 0; i < count; i++)
    {
        scanf("%s", temp);
        words[i] = (char *) malloc(strlen(temp) * sizeof(char));
        strcpy(words[i], temp);
    }
    puts("Here are your words:");
    for (int i = 0; i < count; i++)
    {
        puts(words[i]);
    }

    free(temp);
    for (int i = 0; i < count; i++)
    {
        free(words[i]);
    }
}