#include "card.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "extlib.h"

#define _PILE_BLOCK_SIZE ((size_t)256)

int _card_cmp(const card_t *a, const card_t *b) {
    return (
        a->suit < b->suit ? -1 :
        a->suit > b->suit ? +1 :
        a->rank < b->rank ? -1 :
        a->rank > b->rank ? +1 :
        0
    );
}

const comp_t card_cmp = (comp_t)_card_cmp;

bool functional(card_t card) {
    return (
        card.rank == 2 ||
        card.rank == 3 ||
        card.rank == 7 ||
        card.rank == J ||
        card.rank == Q
    );
}

bool match(card_t card1, card_t card2) {
    return (
        card1.suit == card2.suit ||
        card1.rank == card2.rank
    );
}

int sput_suit(suit_t s, char *str) {
    switch (s) {
        case SPADE:
            return sprintf(str, "Spades");
            break;
        case HEART:
            return sprintf(str, "Hearts");
            break;
        case DIAMS:
            return sprintf(str, "Diamonds");
            break;
        case CLUBS:
            return sprintf(str, "Clubs");
            break;
        default:
            return -1;
    }
}

int sput_rank(rank_t r, char *str) {
    if (r < 2)
        return -1;
    switch (r) {
        case 11:
            return sprintf(str, "J");
        case 12:
            return sprintf(str, "Q");
        case 13:
            return sprintf(str, "K");
        case 14:
            return sprintf(str, "A");
        default:
            return sprintf(str, "%d", r);
    }
}

int sput_card(card_t c, char *str) {
    char suit_str[16];
    char rank_str[16];
    if (sput_suit(c.suit, suit_str) < 0)
        return -1;
    if (sput_rank(c.rank, rank_str) < 0)
        return -1;
    return sprintf(str, "%s %s", suit_str, rank_str);
}

pile_t *new_pile() {
    pile_t *pile = malloc(sizeof(pile_t));
    pile->count = 0;
    pile->capacity = _PILE_BLOCK_SIZE;
    pile->cards = calloc(_PILE_BLOCK_SIZE, sizeof(card_t));
    return pile;
}

void delete_pile(pile_t *pile) {
    free(pile->cards);
    free(pile);
}

void resize_pile(pile_t *pile, size_t size) {
    pile->capacity = size;
    pile->cards = realloc(pile->cards, size * sizeof(card_t));
}

void fit_pile(pile_t *pile) {
    size_t block = pile->count / _PILE_BLOCK_SIZE;
    pile->count % _PILE_BLOCK_SIZE != 0 ? ++block : 0;
    block != 0 ? 0 : ++block;
    size_t size = block * _PILE_BLOCK_SIZE;
    if (size != pile->capacity) {
        resize_pile(pile, size);
    }
}

void generate_pile(pile_t *pile, size_t deck) {
    resize_pile(pile, deck * 52);
    pile->count = 0;
    for (size_t i = 0; i < deck; ++i) {
        for (suit_t suit = 0; suit < 5; ++suit) {
            for (rank_t rank = 2; rank < 15; ++rank) {
                card_t card = {suit, rank};
                pile->cards[pile->count++] = card;
            }
        }
    }
    fit_pile(pile);
}

void sort_pile(const pile_t *pile) {
    qsort(pile->cards, pile->count, sizeof(card_t), card_cmp);
}

void shuffle_pile(const pile_t *pile) {
    qsort(pile->cards, pile->count, sizeof(card_t), rand_cmp);
}

// card_t *search_card(const pile_t *pile, const card_t *card) {
//     return bsearch(card, pile->cards, pile->count, sizeof(card_t), card_cmp);
// }

card_t *search_card(const pile_t *pile, const card_t *card) {
    for (size_t i = 0; i < pile->count; ++i) {
        card_t *ptr = pile->cards + i;
        if (
            ptr->suit == card->suit &&
            ptr->rank == card->rank
        ) {
            return ptr;
        }
    }
    return NULL;
}

card_t *last_card(const pile_t *pile) {
    return &pile->cards[pile->count - 1];
}

void add_card(pile_t *pile, card_t card) {
    ++pile->count;
    fit_pile(pile);
    pile->cards[pile->count - 1] = card;
}

card_t draw_card(pile_t *pile) {
    card_t card = *last_card(pile);
    --pile->count;
    fit_pile(pile);
    return card;
}

void remove_card(pile_t *pile, card_t *card) {
    if (pile->count != 1)
        memswap(card, last_card(pile), sizeof(card_t));
    --pile->count;
    fit_pile(pile);
}

void remove_cards(pile_t *pile, card_t *card, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        remove_card(pile, card + i);
    }
}

bool empty(pile_t *pile) {
    return !pile->count;
}
