#include "universal_set.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define __using_generic_search(func, type)\
void *func(type *key, type *ptr, int count) {\
    for (int i = 0; i < count; ++i) {\
        if (ptr[i] == *key) return ptr + i;\
    }\
    return NULL;\
}

__using_generic_search(_searchc, char)
__using_generic_search(_searchi, int)
__using_generic_search(_searchd, double)

size_t _type(int type) {
    switch (type) {
        case CHAR:
            return CHAR;
        case INT:
            return INT;
        case DOUBLE:
            return DOUBLE;
        default:
            assert(0);
    }
}

size_t _mem(int card) {
    size_t c = (unsigned)card;
    size_t block = c / 64;
    c % 64 != 0 ? ++block : 0;
    block != 0 ? 0 : ++block;
    return block * 64;
}

void *_safe(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Failed to assign memory!\n");
        exit(-1);
    }
    return ptr;
}

void *_search(void *elem, uset *set) {
    uset *S = set;
    switch (S->type) {
        case CHAR:
            return _searchc(elem, S->elem, S->card);
        case INT:
            return _searchi(elem, S->elem, S->card);
        case DOUBLE:
            return _searchd(elem, S->elem, S->card);
        default:
            assert(0);
    }
}

void newSet(uset **set, int type) {
    uset *S = *set;
    S->card = 0;
    S->type = type;
    S->elem = _safe(calloc(INITSETSIZE, _type(type)));
}

void deletSet(uset **set) {
    uset *S = *set;
    free(S->elem);
    free(S);
}

void addElem(void *elem, uset *set) {
    uset *S = set;
    size_t c = (unsigned)S->card;
    size_t t = _type(S->type);
    size_t m = _mem(S->card);
    if (_search(elem, S) != NULL) return;
    ++c;
    if (c > m) {
        m += 64 * t;
        S->elem = _safe(realloc(S->elem, m * t));
    }
    switch (S->type) {
        case CHAR: {
            char *ptr = S->elem;
            char *e = elem;
            ptr[S->card] = *e;
            break;
        }
        case INT: {
            int *ptr = S->elem;
            int *e = elem;
            ptr[S->card] = *e;
            break;
        }
        case DOUBLE: {
            double *ptr = S->elem;
            double *e = elem;
            ptr[S->card] = *e;
            break;
        }
        default: assert(0);
    }
    ++S->card;
}

void remElem(void *elem, uset *set) {
    uset *S = set;
    size_t c = (unsigned)S->card;
    size_t t = _type(S->type);
    void *dest = _search(elem, S);
    if (dest == NULL) return;
    --S->card;
    switch (S->type) {
        case CHAR: {
            char *ptr = S->elem;
            char *d = dest;
            *d = ptr[S->card];
            break;
        }
        case INT: {
            int *ptr = S->elem;
            int *d = dest;
            *d = ptr[S->card];
            break;
        }
        case DOUBLE: {
            double *ptr = S->elem;
            double *d = dest;
            *d = ptr[S->card];
            break;
        }
        default: assert(0);
    }
    size_t m = _mem(S->card);
    if (m < c) {
        S->elem = _safe(realloc(S->elem, m * t));
    }
}
