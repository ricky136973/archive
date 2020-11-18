#include "table.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "extlib.h"
#include "card.h"

table_t *new_table(size_t decks) {
    table_t *table = malloc(sizeof(table_t));
    table->pool = new_pile();
    table->discard = new_pile();
    table->todraw = 1;
    table->counter = true;

    pile_t *pool = table->pool;
    resize_pile(pool, decks * 52);
    size_t count = 0;
    for (size_t i = 0; i < decks; ++i) {
        for (suit_t suit = 0; suit < 4; ++suit) {
            for (rank_t rank = 2; rank < 15; ++rank) {
                card_t card = {suit, rank};
                pool->cards[count++] = card;
            }
        }
    }
    pool->count = count;
    fit_pile(pool);
    shuffle_pile(pool);

    return table;
}

void delete_table(table_t *table) {
    delete_pile(table->pool);
    delete_pile(table->discard);
    free(table);
}

void reshuffle(table_t *table) {
    card_t card = draw_card(table->discard);
    memswap(table->pool, table->discard, sizeof(pile_t));
    add_card(table->discard, card);
    shuffle_pile(table->pool);
}
