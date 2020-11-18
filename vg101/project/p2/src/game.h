#ifndef ONECARD_GAME_H
#define ONECARD_GAME_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "extlib.h"
#include "client.h"
#include "card.h"
#include "table.h"
#include "player.h"

typedef struct _game {
    int n;
    int c;
    int d;
    int r;
    int a;
    FILE *flog;
    client_t *client;
    player_t **players;
    player_t *action;
    player_t *winner;
} game_t;

game_t *new_game(int n, int c, int d, int r, int a, char *fname);
void delete_game(game_t *game);
void start(game_t *game);

#endif //ONECARD_GAME_H
