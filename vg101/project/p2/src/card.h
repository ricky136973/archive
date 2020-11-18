#ifndef ONECARD_CARD_H
#define ONECARD_CARD_H

#include <stddef.h>
#include <stdbool.h>

#include "extlib.h"

#define J 11
#define Q 12
#define K 13
#define A 14

typedef enum _suit {
    SPADE = 0,
    HEART = 1,
    DIAMS = 2,
    CLUBS = 3
} suit_t;

typedef int rank_t;

typedef struct _card {
    suit_t suit;
    rank_t rank;
} card_t;

extern const comp_t card_cmp;

bool functional(card_t card);
bool match(card_t card1, card_t card2);

int sput_suit(suit_t s, char *str);
int sput_rank(rank_t r, char *str);
int sput_card(card_t c, char *str);

typedef struct _pile {
    size_t capacity;
    size_t count;
    card_t *cards;
} pile_t;

pile_t *new_pile();
void delete_pile(pile_t *pile);
void resize_pile(pile_t *pile, size_t size);
void fit_pile(pile_t *pile);
void generate_pile(pile_t *pile, size_t deck);
void sort_pile(const pile_t *pile);
void shuffle_pile(const pile_t *pile);
card_t *search_card(const pile_t *pile, const card_t *card);
card_t *last_card(const pile_t *pile);
void add_card(pile_t *pile, card_t card);
card_t draw_card(pile_t *pile);
void remove_card(pile_t *pile, card_t *card);
void remove_cards(pile_t *pile, card_t *card, size_t count);
bool empty(pile_t *pile);

#endif //ONECARD_CARD_H
