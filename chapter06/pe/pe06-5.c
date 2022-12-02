#include <stdio.h>

int main(void)
{
    int i, j, size;
    char letter;
    printf("输入大写字母： ");
    scanf("%c", &letter);
    size = letter-'A'+1;

    for(i=0; i<size; i++){
        for(j=size-i;j>0;j--){
            printf(" ");
        }
        for(j=0; j<i+1; j++){
            printf("%c",'A'+j);
        }
        for(j=i; j>0; j--){
            printf("%c", 'A'+j-1);
        }
        printf("\n");
    }

    return 0;
}
