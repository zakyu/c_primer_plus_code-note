#include <stdio.h>

int main(void)
{
    char ch;
    int count=0;    
    while((ch=getchar())!='#'){
        printf("%c:%d ", ch, ch);
        count++;
        if (count > 7) {
            printf("\n");
            count=0;
        }
    }
    printf(\n);

    return 0;
}
