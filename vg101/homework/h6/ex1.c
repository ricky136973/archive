#include "assignment.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>

void ex1() {
    size_t n;
    while (!scanf("%zu", &n));
    int *a = calloc(n, sizeof(int));
    for (size_t i = 0; i < n; ++i) {
        int *ptr = &a[i];
        while (!scanf("%d", ptr));
    }

    int m = INT_MIN;
    for (size_t i = 0; i < n; ++i) {
        a[i] > m ? m = a[i] : 0;
    }
    srand(time(NULL));
    int r = rand() % m;
    for (size_t i = 0; i < n; ++i) {
        a[i] > r ? printf("%d ", a[i]) : 0;
    }
    free(a);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex1();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H