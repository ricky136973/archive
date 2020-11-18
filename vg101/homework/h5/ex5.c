#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __GNUC__
#define __unused__ __attribute__((unused))
#else //__GNUC__
#define __unused__
#endif //__GNUC__

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

typedef int (*comp_t)(const void*, const void*);

int _rand_cmp(__unused__ const void *a, __unused__ const void *b) {
    return rand() % 2 * 2 - 1;
}

int _card_cmp(const card_t *a, const card_t *b) {
    return
        a->suit < b->suit ? -1 : a->suit > b->suit ? 1 :
        a->rank < b->rank ? -1 : a->rank > b->rank ? 1 :
        0;
}

const comp_t card_cmp = (comp_t)_card_cmp;
const comp_t rand_cmp = (comp_t)_rand_cmp;

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
            break;
        case 12:
            return sprintf(str, "Q");
            break;
        case 13:
            return sprintf(str, "K");
            break;
        case 14:
            return sprintf(str, "A");
            break;
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

void print_cards(const card_t *cards, size_t count) {
    char card_str[16];
    for (size_t i = 0; i < count; ++i) {
        sput_card(cards[i], card_str);
        printf("%s\n", card_str);
    }
}

void ex5() {
    srand((unsigned)time(NULL));

    card_t cards[52];
    int i = 0;
    for (suit_t s = 0; s < 4; ++s) {
        for (rank_t r = 2; r < 15; ++r) {
            cards[i].suit = s;
            cards[i].rank = r;
            ++i;
        }
    }

    print_cards(cards, 52);
    qsort(cards, 52, sizeof(card_t), rand_cmp);
    print_cards(cards, 52);
    qsort(cards, 52, sizeof(card_t), card_cmp);
    print_cards(cards, 52);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex5();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H