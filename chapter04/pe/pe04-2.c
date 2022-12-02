#include <stdio.h>
#include <string.h>

int main(void)
{
    char fname[20], lname[20];
    int flen, llen;

    printf("输入名和姓：");
    scanf("%s %s", fname, lname);
    printf("\"%s %s\"\n", fname, lname);
    printf("\"%20s %20s\"\n", fname, lname);
    printf("\"%-20s %-20s\"\n", fname, lname);
    flen = strlen(fname);
    llen = strlen(lname);
    printf("\"%*s %*s\"\n", flen+3, fname, llen+3, lname);

    return 0;
}
