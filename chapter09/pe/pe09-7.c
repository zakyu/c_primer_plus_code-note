#include <stdio.h>
#include <ctype.h>

int locate(char);

int main(void)
{
    char ch;
    int location;
    while(scanf("%c", &ch), ch != '\n') {
        location = locate(ch);
        if (location < 1) {
            printf("Not a alpha.\n");
            continue;
        }
        printf("location of %c is %d.\n", ch, location);
    }

    return 0;
}

int locate(char ch)
{
    if(!isalpha(ch))
        return -1;
    ch = toupper(ch);
    return ch-'A'+1;
}
