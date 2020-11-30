#ifndef JOJ
#include "assignment.h"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long int number_t;

static const auto f = [] (number_t u) {
    return u & 1 ? 3 * u + 1 : u >> 1;
};

number_t count_bit(number_t n) { 
    return n ? n & 1 ? 0 : count_bit(n >> 1) + 1 : 0;
}

number_t que1(number_t a) {
    number_t N = 0;
    for (number_t u = a; u != 1; u = f(u), ++N);
    return N;
}

number_t que2(number_t M) {
    std::vector<number_t> N(M + 1);
    N[0] = N[1] = 0;
    for (number_t a = 2; a <= M; ++a) {
        number_t u = a;
        number_t n = 0;
        while (u >= a) {
            number_t k = count_bit(u);
            if (k == 0) {
                u = 3 * u + 1;
                ++n;
            } else {
                u >>= k;
                n += k;
            }
        }
        N[a] = N[u] + n;
    }
    return number_t(max_element(N.begin(), N.end()) - N.begin());
}

void ex4() {
    number_t mode, value;
    std::cin >> mode >> value;
    std::cout << (mode == 1 ? que1 : que2)(value);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex4();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
