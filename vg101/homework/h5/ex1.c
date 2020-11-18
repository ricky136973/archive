#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void ex1() {
    unsigned n, count = 0;
    while (!scanf("%u", &n));
    bool *flag = calloc(n, sizeof(bool)); // Tag for non-primes
    unsigned *prime = calloc(n, sizeof(unsigned)); // Primes

    for (unsigned i = 2; i < n; ++i) {
        if (!flag[i]) {
            prime[count++] = i;
            printf("%u ", i);
        }
        for (unsigned j = 0; i * prime[j] < n; ++j) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex1();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H