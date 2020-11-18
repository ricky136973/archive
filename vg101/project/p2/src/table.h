#ifndef ONECARD_TABLE_H
#define ONECARD_TABLE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "card.h"

typedef struct _table {
    pile_t *pool;
    pile_t *discard;
    size_t todraw;
    bool counter;
} table_t;

table_t *new_table(size_t decks);
void delete_table(table_t *table);
void reshuffle(table_t *table);

#endif //ONECARD_TABLE_H
