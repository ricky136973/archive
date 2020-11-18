#ifndef ONECARD_EXTLIB_H
#define ONECARD_EXTLIB_H

#ifdef __GNUC__
#define __unused__ __attribute__((unused))
#else
#define __unused__
#endif // __GNUC__

#include <stddef.h>

typedef int (*comp_t)(const void*, const void*);

int randi(int imin, int imax);
int rand_cmp(__unused__ const void *a, __unused__ const void *b);
void memswap(void *a, void *b, size_t size);
// void qshuffle(void *ptr, size_t count, size_t size);
// void bshuffle(void *ptr, size_t count, size_t size);

int cls();

#endif //ONECARD_EXTLIB_H
