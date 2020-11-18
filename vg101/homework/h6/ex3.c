#include "assignment.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define WORD_MAX_LENGTH 0x10000

typedef char word_t[WORD_MAX_LENGTH];

void ex3() {
    FILE *fsntc = fopen("./sentence.txt", "r");
    FILE *fword = fopen("./word.txt", "r");
    FILE *fcnt = fopen("./count.txt", "w");

    word_t word1, word2;
    size_t count = 0;
    fscanf(fword, "%s", word1);
    while (!feof(fsntc)) {
        fscanf(fsntc, "%s", word2);
        strcmp(word1, word2) ? 0 : ++count;
    }
    fprintf(fcnt, "%zu", count);

    fclose(fsntc);
    fclose(fword);
    fclose(fcnt);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex3();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
