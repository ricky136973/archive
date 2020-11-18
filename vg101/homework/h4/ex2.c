#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void ex2() {
    int a, b;
    while (!scanf("%d%d", &a, &b));
    printf("%d\n", gcd(a, b));
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex2();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H