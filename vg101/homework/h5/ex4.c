#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <tgmath.h>

typedef long double real_t;

// real_t f(real_t x) {
//     const real_t v0 = 30L;
//     const real_t t0 = acos(-1L)/6;
//     const real_t g = 9.81L;
//     const real_t a = -g/(2*v0*v0*cos(t0)*cos(t0));
//     const real_t b = tan(t0);
//     const real_t c = 1.5L;
//     return a*x*x+b*x+c;
// }

typedef struct _func {
    real_t a, b, c;
} func_t;

real_t calc(const func_t *f, real_t x) {
    return f->a * x * x + f->b * x + f->c;
}

real_t bsolve(const func_t *f, real_t A, real_t B) {
    real_t M = (A + B) / 2;
    if (B - A < (real_t)FLT_EPSILON) return M;
    if (calc(f, A) * calc(f, M) <= 0) return bsolve(f, A, M);
    if (calc(f, M) * calc(f, B) <= 0) return bsolve(f, M, B);
    return M;
}

void ex4() {
    real_t v0, t0, h, A, B, g = 9.81L;
    while (!scanf("%Lf%Lf%Lf%Lf%Lf", &v0, &t0, &h, &A, &B));
    t0 = t0 / 180L * acos(-1L);
    real_t a = -g / (2 * v0 * v0 * cos(t0) * cos(t0));
    real_t b = tan(t0);
    real_t c = h;
    func_t f = {a, b, c};
    printf("%.6Lf", bsolve(&f, A, B));
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex4();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H