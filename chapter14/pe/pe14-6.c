#include <stdio.h>

#define LEN 20

struct player
{
    int     id;
    char    first[LEN];
    char    last[LEN];
    int     game_played;
    int     hit;
    int     base;
    int     RBI;
    int     hit_rate;
};
typedef struct player Player;

int main(void)
{
    Player players[20];

    //TODO

    return 0;
}