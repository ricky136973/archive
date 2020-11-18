#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t count_substr(const char *str, const char *substr) {
    size_t count = 0;
    for (
        const char *ptr = (void*)(strstr(str, substr) + 1);
        ptr != (void*)1;
        ptr = (void*)(strstr(ptr, substr) + 1)
    ) ++count;
    return count;
}

void ex3() {
    char str[0x10000];
    char substr[0x100];
    while (!fgets(str, 0x10000, stdin) || !fgets(substr, 0x100, stdin));
    for (int i = 0; i < 256; ++i) {
        if (substr[i] == '\n' || substr[i] == '\0') {
            substr[i] = '\0';
            break;
        }
    }
    printf("The string '%s' occurs %zu times", substr, count_substr(str, substr));
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex3();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H