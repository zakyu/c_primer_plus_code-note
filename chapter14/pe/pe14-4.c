#include <stdio.h>
#define LEN 40

struct member {
    char ID[LEN];
    struct {
        char first[LEN];
        char middle[LEN];
        char last[LEN];
    };
};

typedef struct member MEMBER;
void print(MEMBER * members, int count);

int main(void)
{
    MEMBER members[5] = {
        { "A00001", {"A", "B", "C"}},
        { "A00002", {"A", "B", "C"}},
        { "B00001", {"A", "", "C"}},
        { "B00002", {"A", "B", "C"}},
        { "B00003", {"A", "B", "C"}}
    };
    
    print(members, 5);

    return 0;
}

void print(MEMBER * members, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (members[i].middle[0] == '\0')
            printf("%s, %s -- %s\n", members[i].first,
                members[i].last, members[i].ID);
        else
            printf("%s, %s %c. -- %s\n", members[i].first,
                members[i].last, members[i].middle[0], members[i].ID);
    }
}