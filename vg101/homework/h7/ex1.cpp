#ifndef JOJ
#include "assignment.h"
#endif

#include <iostream>

void ex1() {
    int year1, year2, age;
    std::cin >> year1 >> age >> year2;
    std::cout << age + year2 - year1;
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex1();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
