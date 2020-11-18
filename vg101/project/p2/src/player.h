#ifndef ONECARD_PLAYER_H
#define ONECARD_PLAYER_H

#include "card.h"
#include "table.h"
#include "client.h"

typedef struct _player {
    char *name;
    int score;
    pile_t *stock;
    struct _player *prev_player;
    struct _player *next_player;
    table_t *table;
    client_t *client;
    void *game;
} player_t;

player_t *new_player();
void delete_player(player_t *player);
void resign_player(player_t *player);
card_t draw(player_t *player);
void play(player_t *player);

extern int output(void *game, char *str);

extern void pass_to_player(player_t *player);
extern void win(player_t *player);

#endif //ONECARD_PLAYER_H
