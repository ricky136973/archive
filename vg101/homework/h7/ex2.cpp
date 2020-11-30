#ifndef JOJ
#include "assignment.h"
#endif

#include <iostream>
#include <iomanip>

typedef long double currency_t;

static const currency_t RATE_USD_TO_CNY = 6.20350L;
static const currency_t RATE_CNY_TO_USD = 1.0L / RATE_USD_TO_CNY;

void ex2() {
    int mode, precision;
    currency_t amount;
    std::cin >> mode >> amount >> precision;
    std::cout
        << std::showpoint << std::setprecision(precision)
        << amount * (mode == 1 ? RATE_USD_TO_CNY : RATE_CNY_TO_USD);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex2();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
