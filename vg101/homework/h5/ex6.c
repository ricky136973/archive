#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b) do {\
    a ^= b;\
    b ^= a;\
    a ^= b;\
} while (0)

// #define TEST

typedef unsigned long int ulong_t;

ulong_t mult(ulong_t a, ulong_t b);

void ex6() {
    ulong_t a, b;
    srand(time(NULL));
    #ifndef TEST
    a = rand();
    b = rand();
    printf("%lu*%lu=%lu %lu\n", a, b, mult(a, b), (ulong_t)RAND_MAX);
    #else //TEST
    for (int i = 0; i < 1000000; i++) {
        a = rand();
        b = rand();
        if (mult(a, b) != a * b) {
            fprintf(stderr,
                "Error (%d): a=%lu, b=%lu, a*b=%lu, k(a,b)=%lu\n",
                i, a, b, a * b, mult(a, b)
            );
            exit(-1);
        }
    }
    #endif //TEST
}

ulong_t mult(ulong_t a, ulong_t b) {
    int i, n, N;
    ulong_t x0, x1, y0, y1;
    ulong_t z0, z1, z2, z3;
    if (a < b) SWAP(a, b); // Ensure a >= b
    if (b == 0) return 0; // a * 0 == 0
    if (b == 1) return a; // a * 1 == a
    for (n = 0, i = 1; (ulong_t)i <= b; i <<= 1, n++); // Get the digits of b
    for (N = n; (ulong_t)i <= a; i <<= 1, N++); // Get the digits of a
    n >>= 1; // Half the n
    N >>= 1; // Half the N

    x0 = a & ((1 << N) - 1); // Get the lower half of a
    y0 = b & ((1 << n) - 1); // Get the lower half of b
    x1 = a >> N; // Get the higher half of a
    y1 = b >> n; // Get the higher half of b
    z0 = mult(x0, y0); // Recursively calculate x0 * y0
    z1 = mult(x1, y0); // Recursively calculate x1 * y0
    z2 = mult(x0, y1); // Recursively calculate x0 * y1
    z3 = mult(x1, y1); // Recursively calculate x1 * y1
    i = N + n; // Get the digit of a * b
    return (z3 << i) + (z2 << n) + (z1 << N) + z0; // Sum up the result
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex6();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H