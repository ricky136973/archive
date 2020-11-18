#include "player.h"

#include <stdlib.h>
#include <stdbool.h>

#include "card.h"
#include "table.h"

player_t *new_player() {
    player_t *player = malloc(sizeof(player_t));
    player->score = 0;
    player->stock = new_pile();
    player->prev_player = NULL;
    player->next_player = NULL;
    player->table = NULL;
    player->client = NULL;
    player->game = NULL;
    player->name = malloc(256);
    return player;
}

void delete_player(player_t *player) {
    delete_pile(player->stock);
    free(player->name);
    free(player);
}

void resign_player(player_t *player) {
    player->prev_player->next_player = player->next_player;
    player->next_player->prev_player = player->prev_player;
}

card_t draw(player_t *player) {
    if (empty(player->table->pool)) {
        reshuffle(player->table);
        output(
            player->game,
            "Stock pile exhausted. "
            "Shuffling the discard pile and restore the stock pile.\n"
        );
    }
    card_t card = draw_card(player->table->pool);
    add_card(player->stock, card);
    return card;
}

void play(player_t *player) {
    void *game = player->game;
    client_t *client = player->client;
    pile_t *stock = player->stock;
    table_t *table = player->table;
    card_t card = *last_card(table->discard);

    int count = 0;
    int opt = 0;
    card_t options[52];
    sort_pile(stock);
    options[0] = stock->cards[0];
    if (
        match(card, stock->cards[0]) && (
            functional(stock->cards[0]) ||
            table->todraw == 1
        )
    ) opt = 1;
    for (size_t i = 0; i < stock->count; ++i) {
        if (card_cmp(&options[count], &stock->cards[i])) {
            options[++count] = stock->cards[i];
            if (
                match(card, stock->cards[i]) && (
                    functional(stock->cards[i]) ||
                    table->todraw == 1
                )
            ) opt = count + 1;
        }
    }
    ++count;

    char *card_str = malloc(16);
    char *buff = malloc(256);
    client->clear();
    sprintf(buff, "%s's turn:\n", player->name);
    client->prompt(buff);
    sput_card(card, card_str);
    sprintf(buff, "Card to go: %s\n", card_str);
    client->prompt(buff);
    sprintf(buff, "You have %zu card(s) in total.\n", stock->count);
    client->prompt(buff);
    sprintf(buff, "Choose your card to play (identical cards ommitted):\n");
    client->prompt(buff);
    for (int i = 0; i < count; ++i) {
        sput_card(options[i], card_str);
        sprintf(buff, "[%2d] %s\n", i + 1, card_str);
        client->prompt(buff);
    }
    sprintf(buff, "Enter 0 to pass and draw %zu card(s).\n", table->todraw);
    client->prompt(buff);

    while (true) {
        int id = client->query(0, count, opt, "Enter your choice: ");
        if (id == 0) {
            sprintf(buff, "%s draws:", player->name);
            output(game, buff);
            for (size_t i = 0; i < table->todraw; ++i) {
                sput_card(draw(player), card_str);
                sprintf(buff, " %s,", card_str);
                output(game, buff);
            }
            output(game, "\n");
            table->todraw = 1;
            player_t *topass = (table->counter ?
                player->next_player :
                player->prev_player
            );
            pass_to_player(topass);
        } else {
            card_t option = options[id - 1];
            if (table->todraw > 1) {
                if (!match(card, option) || !functional(option)) {
                    client->prompt("You can't play this card!\n");
                    continue;
                }
            } else {
                if (!match(card, option)) {
                    client->prompt("You can't play this card!\n");
                    continue;
                }
            }

            int count = 0;
            for (size_t i = 0; i < stock->count; ++i) {
                card_t card = stock->cards[i];
                if (
                    card.suit == option.suit &&
                    card.rank == option.rank
                ) ++count;
            }
            if (count != 1) {
                sprintf(buff, "You have %d cards of this kind. How many to play?\n", count);
                client->prompt(buff);
                count = client->query(1, count, count, "Enter your choice: ");
            }
            sput_card(option, card_str);
            sprintf(buff, "%s plays: %s * %d\n", player->name, card_str, count);
            output(game, buff);

            if ((int)player->stock->count == count) {
                client->prompt("You win!\n");
                sprintf(buff, "%s wins!\n", player->name);
                output(game, buff);
                win(player);
                break;
            }

            remove_cards(
                stock,
                search_card(stock, &option),
                (size_t)count
            );

            add_card(table->discard, option);
            player_t *topass = (table->counter ?
                player->next_player :
                player->prev_player
            );
            switch (option.rank) {
                case 2:
                    if (table->todraw == 1) {
                        table->todraw = 0;
                    }
                    table->todraw += 2;
                    break;
                case 3:
                    if (table->todraw == 1) {
                        table->todraw = 0;
                    }
                    table->todraw += 3;
                    break;
                case J:
                    topass = topass->next_player;
                    break;
                case Q:
                    table->counter = !table->counter;
                    topass = (table->counter ?
                        player->next_player :
                        player->prev_player
                    );
                    break;
                default:
                    table->todraw = 1;
            }
            pass_to_player(topass);
            // sput_card(option, card_str);
            // sprintf(buff, "%s plays: %s\n", player->name, card_str);
            // output(game, buff);

            // if (player->stock->count == 0) {
            //     client->prompt("You win!\n");
            //     sprintf(buff, "%s wins!\n", player->name);
            //     output(game, buff);
            //     win(player);
            //     break;
            // }
        }

        sort_pile(stock);
        sprintf(buff, "%s cards:", player->name);
        output(game, buff);
        for (size_t i = 0; i < stock->count; ++i) {
            sput_card(stock->cards[i], card_str);
            sprintf(buff, " %s,", card_str);
            output(game, buff);
        }
        output(game, "\n");
        break;
    }
    
    free(card_str);
    free(buff);
}
