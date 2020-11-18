#include "extlib.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randi(int imin, int imax) {
    return rand() % (imax - imin + 1) + imin;
}

int rand_cmp(__unused__ const void *a, __unused__ const void *b) {
    return rand() % 2 * 2 - 1;
}

void memswap(void *a, void *b, size_t size) {
    void *t = malloc(size);
    memmove(t, a, size);
    memmove(a, b, size);
    memmove(b, t, size);
    free(t);
}

// void qshuffle(void *ptr, size_t count, size_t size) {
//     void *end = (void*)((size_t)ptr + count * size);
//     for (void* i = ptr; i != end; i = (void*)((size_t)i + size)) {
//         void *j = (void*)((size_t)ptr + rand() % count * size);
//         memswap(i, j, size);
//     }
// }

// void bshuffle(void *ptr, size_t count, size_t size) {
//     if (count < 2) return;

//     size_t bytes = count * size;
//     size_t halfs = count / 2 * size;
//     void *temp = malloc(bytes);
//     memset(temp, 0, bytes);
//     void *head = temp;
//     void *tail = (void*)((size_t)temp + bytes - size);
//     void *beg = ptr;
//     void *end = (void*)((size_t)ptr + bytes);
//     void *mid = (void*)((size_t)ptr + halfs);
//     srand((unsigned)time(NULL));

//     for (void* i = beg; i != end; i = (void*)((size_t)i + size)) {
//         if (rand() & 1) {
//             memcpy(head, i, size);
//             head = (void*)((size_t)head + size);
//         } else {
//             memcpy(tail, i, size);
//             tail = (void*)((size_t)tail - size);
//         }
//     }
//     memcpy(ptr, temp, bytes);
//     free(temp);

//     bshuffle(beg, count / 2, size);
//     bshuffle(mid, count - count / 2, size);
// }

int cls() {
    #ifdef _WIN32
    return system("cls");
    #else
    return system("clear");
    #endif
}
