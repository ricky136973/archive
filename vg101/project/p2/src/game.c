#include "game.h"

#include <stdlib.h>
#include <assert.h>

#include "extlib.h"
#include "client.h"
#include "card.h"
#include "table.h"
#include "player.h"

int output(void *game, char *str) {
    game_t *g = (game_t*)game;
    if (g->a) {
        printf("%s", str);
        fflush(stdout);
    }
    fprintf(g->flog, "%s", str);
    return fflush(g->flog);
}

void pass_to_player(player_t *player) {
    game_t *game = (game_t*)player->game;
    game->action = player;
}

void win(player_t *player) {
    game_t *game = (game_t*)player->game;
    game->winner = player;
    pass_to_player(player);
}

game_t *new_game(int n, int c, int d, int r, int a, char *fname) {
    game_t *game = malloc(sizeof(game_t));

    game->n = n;
    game->c = c;
    game->d = d;
    game->r = r;
    game->a = a;
    game->flog = fopen(fname, "w");

    client_t *client = new_client(a ? bot_client_base : std_client_base);
    player_t **players = calloc((size_t)n, sizeof(player_t*));
    for (int i = 0; i < n; ++i) {
        players[i] = new_player();
        players[i]->game = game;
        players[i]->client = client;
        sprintf(players[i]->name, "Player %d", i + 1);
    }
    for (int i = 0; i < n; ++i) {
        players[i]->prev_player = players[(i - 1 + n) % n];
        players[i]->next_player = players[(i + 1 + n) % n];
    }
    game->client = client;
    game->players = players;
    game->action = NULL;
    game->winner = NULL;

    return game;
}

void delete_game(game_t *game) {
    for (int i = 0; i < game->n; ++i) {
        delete_player(game->players[i]);
    }
    free(game->players);
    delete_client(game->client);
    fclose(game->flog);
    free(game);
}

void start(game_t *game) {
    int n = game->n;
    int c = game->c;
    int d = game->d;
    int r = game->r;

    char buff[256];
    char card_str[16];
    sprintf(buff,
        "---- Initial setup ----\n"
        "Number of rounds: %d\n"
        "Number of decks: %d\n"
        "Number of players: %d\n\n",
        r, d, n
    );
    output(game, buff);

    for (int round = 1; round <= r; ++round) {
        table_t *table = new_table((size_t)d);
        for (int i = 0; i < n; ++i) {
            game->players[i]->table = table;
        }
        sprintf(buff,
            "---- Round setup ----\n"
            "Shuffling cards...\n"
            "Shuffle result:\n"
        );
        output(game, buff);
        for (int i = 0; i < (int)table->pool->count; ++i) {
            sput_card(table->pool->cards[i], card_str);
            sprintf(buff, "%s, ", card_str);
            output(game, buff);
        }
        output(game, "\n\n");

        output(game, "Dealing cards...\n");
        for (int i = 0; i < n; ++i) {
            player_t *player = game->players[i];
            sprintf(buff, "%s:", player->name);
            output(game, buff);
            for (int j = 0; j < c; ++j) {
                sput_card(draw(player), card_str);
                sprintf(buff, " %s,", card_str);
                output(game, buff);
            }
            output(game, "\n");
        }
        output(game, "\n");

        if (game->action == NULL) {
            output(game, "Determining the playing order...\n");
            int rank = 15;
            for (int i = 0; i < n; ++i) {
                card_t card = draw_card(table->pool);
                sput_card(card, card_str);
                sprintf(buff, "%s: %s\n", game->players[i]->name, card_str);
                output(game, buff);
                if (card.rank < rank) {
                    rank = card.rank;
                    game->action = game->players[i];
                }
                add_card(table->discard, card);
            }
            sprintf(buff, "The game will start with %s\n\n", game->action->name);
            output(game, buff);
        }

        output(game, "---- Round start ----\n");
        card_t card = draw_card(table->pool);
        sput_card(card, card_str);
        sprintf(buff, "First card: %s\n", card_str);
        add_card(table->discard, card);
        game->winner = NULL;
        while (game->winner == NULL) {
            play(game->action);
        }

        output(game, "\n---- Stats ----\n");
        sprintf(buff, "Round %d result:\n", round);
        output(game, buff);
        for (int i = 0; i < game->n; ++i) {
            player_t *ptr = game->players[i];
            int penalty = (int)ptr->stock->count;
            ptr->score -= penalty;
            sprintf(buff, "%s: %d, total: %d\n", ptr->name, -penalty, ptr->score);
            output(game, buff);
            delete_pile(ptr->stock);
            ptr->stock = new_pile();
        }
        sprintf(buff, "Round %d ends.\n\n", round);
        output(game, buff);
        delete_table(table);
    }
}
