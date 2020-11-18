#ifndef __STDC_WANT_LIB_EXT1__
#define __STDC_WANT_LIB_EXT1__ 1
#endif

#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define MAX_LEN 0x100000

#ifdef __STDC_LIB_EXT1__
#define memmove memmove_s
#endif

typedef char *ptr_t;

void chrreplace(char *str, char ch1, char ch2) {
    ptr_t ptr = str;
    while ((ptr = strchr(ptr, ch1))) {
        *ptr = ch2;
    }
}

void chrdelete(char *str, char ch) {
    ptr_t ptr = str;
    ptr_t *pos = malloc(MAX_LEN * sizeof(ptr_t));
    size_t count = 0;
    while ((ptr = strchr(ptr, ch))) {
        pos[count++] = ptr;
        *ptr = '\0';
        ++ptr;
    }
    size_t len;
    for (size_t i = 0; i < count; ++i) {
        ptr = pos[i] + 1;
        len = strlen(ptr);
        memmove(pos[i] - i, ptr, len);
        *(pos[i] - i + len) = '\0';
    }
    free(pos);
}

void ex6() {
    #ifdef __STDC_LIB_EXT1__
    set_constraint_handler_s(abort_handler_s);
    #endif
    char *str = malloc(MAX_LEN);
    int op;
    printf("Input a string: ");
    while (!scanf("%[^\n]",str));
    printf("* Choose 1 to replace a character or 2 to delete a character: ");
    scanf("%d", &op);
    switch (op) {
        case 1: {
            char ch1[2], ch2[2];
            printf("  Replace character: ");
            scanf("%s", ch1);
            printf("  with: ");
            scanf("%s", ch2);
            chrreplace(str, ch1[0], ch2[0]);
            break;
        }
        case 2: {
            char ch[2];
            printf("  Delete character: ");
            scanf("%s", ch);
            chrdelete(str, ch[0]);
            break;
        }
    }
    printf("New string: %s", str);
    free(str);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex6();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
