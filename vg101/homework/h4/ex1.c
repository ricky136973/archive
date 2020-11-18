#ifndef JOJ
#include "assignment.h"
#endif

#ifdef __STDC_NO_COMPLEX__

typedef struct _complex {
    double _real;
    double _imag;
} complex_t;

complex_t _CMPLX(double x, double y) {
    complex_t z = {x, y};
    return z;
}

#define CMPLX(x, y) (_CMPLX((double)(x), (double)(y)))

double creal(complex_t z) {
    return z._real;
}

double cimag(complex_t z) {
    return z._imag;
}

complex_t cadd(complex_t a, complex_t b) {
    return CMPLX(
        creal(a) + creal(b),
        cimag(a) + cimag(b)
    );
}

complex_t cmul(complex_t a, complex_t b) {
    return CMPLX(
        creal(a) * creal(b) - cimag(a) * cimag(b),
        creal(a) * cimag(b) + cimag(a) * creal(b)
    );
}

#else //__STDC_NO_COMPLEX__

#include <complex.h>

typedef double complex complex_t;

#ifndef CMPLX
#define CMPLX(x, y) ((complex_t)((double)(x) + I * (double)(y)))
#endif

complex_t cadd(complex_t a, complex_t b) {
    return a + b;
}

complex_t cmul(complex_t a, complex_t b) {
    return a * b;
}

#endif //__STDC_NO_COMPLEX__

#include <math.h>
#include <stdio.h>

void ex1() {
    int x1, y1, x2, y2;
    complex_t c;
    char op;
    while (!scanf("%d%di %d%di %c", &x1, &y1, &x2, &y2, &op));
    c =
        op == '+' ? cadd(CMPLX(x1, y1), CMPLX(x2, y2)) :
        op == '*' ? cmul(CMPLX(x1, y1), CMPLX(x2, y2)) :
        CMPLX(0, 0);
    printf("%ld%+ldi\n", lround(creal(c)), lround(cimag(c)));
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex1();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H