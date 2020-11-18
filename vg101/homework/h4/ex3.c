#ifndef JOJ
#include "assignment.h"
#endif

#include <math.h>
#include <complex.h>
#include <string.h>
#include <stdio.h>

typedef double complex complex_t;

#ifndef CMPLX
#define CMPLX(x, y) ((complex_t)((double)(x) + I * (double)(y)))
#endif

typedef struct roots {
    complex_t x1;
    complex_t x2;
} roots_t;

roots_t solve(complex_t a, complex_t b, complex_t c) {
    complex_t sqrt_d = csqrt(b*b-4.0*a*c);
    complex_t x1 = (-b-sqrt_d)/(2.0*a);
    complex_t x2 = (-b+sqrt_d)/(2.0*a);
    roots_t r = {x1, x2};
    return r;
}

int putcmplx(complex_t z) {
    double x = creal(z);
    double y = cimag(z);
    return y == 0 ? printf("%.5lf", x) : printf("%.5lf%+.5lfi", x, y);
}

void ex3() {
    double a, b, c;
    while (!scanf("%lf%lf%lf", &a, &b, &c));
    roots_t r = solve(CMPLX(a, 0), CMPLX(b, 0), CMPLX(c, 0));
    putcmplx(r.x1);
    printf("\n");
    if (r.x2 != r.x1) {
        putcmplx(r.x2);
        printf("\n");
    }
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex3();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H