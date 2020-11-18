#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int days[12] = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

const char *month_name[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char *day_name[7] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

int daytoi(const char *day) {
    for (int i = 0; i < 7; ++i) {
        if (!strcmp(day, day_name[i])) {
            return i;
        }
    }
    return -1;
}

void ex2() {
    int m, d;
    char day[16];
    while (!scanf("%d%s", &m, day));
    --m;
    d = daytoi(day);

    printf("%s\n", month_name[m]);
    for (int i = 0; i < 7; ++i) {
        printf("%s ", day_name[i]);
    }
    printf("\n");
    for (int i = 1 - d; i <= days[m]; ++i) {
        if (i > 0) {
            printf("%3d ", i);
        } else {
            printf("    ");
        }
        if ((i + d) % 7 == 0 && i + d != 0) {
            printf("\n");
        }
    }
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex2();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H