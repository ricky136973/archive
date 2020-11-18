#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <tgmath.h>

#define PI (acos(-1.0L))

typedef long double real_t;

typedef struct _pair {
    real_t a;
    real_t b;
} pair_t;

typedef pair_t (*func_t)(pair_t);

const pair_t zero = {0, 0};

pair_t rectopol(pair_t p) {
    real_t x = p.a;
    real_t y = p.b;
    real_t r = sqrt(x * x + y * y);
    real_t t = atan2(y, x);
    pair_t c = {r, t};
    return c;
}

pair_t poltorec(pair_t p) {
    real_t r = p.a;
    real_t t = p.b;
    real_t x = r * cos(t);
    real_t y = r * sin(t);
    pair_t c = {x, y};
    return c;
}

void mapfunc(pair_t *dest, const pair_t *src, func_t *func, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        dest[i] = (func[i])(src[i]);
    }
}

void ex2() {
    const pair_t c1 = {3, 4.0L / 5.0L};
    const pair_t c2 = {0, log(4.0L)};
    const pair_t c3 = {45.245L, 0.235L};
    const pair_t c4 = {3, PI / 17.0L};
    const pair_t c5 = {4 * cos(PI / 9.0L), 4 * sin(PI / 9.0L)};
    const pair_t c6 = {1, PI / 12.0L};

    pair_t orig[6] = {c1, c2, c3, c4, c5, c6};
    pair_t cvrt[6];
    func_t funcs[6] = {
        rectopol, rectopol, rectopol, poltorec, rectopol, poltorec
    };

    mapfunc(&cvrt[0], &orig[0], funcs, 6);

    for (size_t i = 0; i < 6; ++i) {
        if (funcs[i] == rectopol) {
            real_t x = orig[i].a;
            real_t y = orig[i].b;
            real_t r = cvrt[i].a;
            real_t t = cvrt[i].b;
            printf("%.5Lf%+.5Lfi %.5Lfe%.5Lfi\n", x, y, r, t);
        } else {
            real_t r = orig[i].a;
            real_t t = orig[i].b;
            real_t x = cvrt[i].a;
            real_t y = cvrt[i].b;
            printf("%.5Lfe%.5Lfi %.5Lf%+.5Lfi\n", r, t, x, y);
        }
    }
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex2();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
