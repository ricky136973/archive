#include "assignment.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <tgmath.h>

#define MAX_BUFF 500000
#define MAX_N 500

typedef int scalar_t;
typedef scalar_t matrix_t[MAX_N][MAX_N];

void transpose(matrix_t AT, matrix_t A, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            AT[i][j] = A[j][i];
        }
    }
}

void add(matrix_t C, matrix_t A, matrix_t B, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void mul(matrix_t C, matrix_t A, matrix_t B, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (size_t k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int fputmat(matrix_t mat, size_t n, FILE *stream) {
    int count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            count += fprintf(stream, "%d ", mat[i][j]);
        }
        count += fprintf(stream, "\n");
    }
    return count;
}

void ex4() {
    FILE *fin = fopen("./matrices.txt", "r");
    FILE *fout = fopen("./result.txt", "w");

    scalar_t *buff = calloc(MAX_BUFF, sizeof(scalar_t));
    size_t count;
    for (count = 0; !feof(fin); ++count) {
        while (!fscanf(fin, "%d", &buff[count]));
    }
    size_t n = (size_t)sqrt(count / 2);
    static matrix_t A, B, C, AB, AT, BT, ATBT;
    count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            A[i][j] = buff[count++];
        }
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            B[i][j] = buff[count++];
        }
    }
    free(buff);

    add(C, A, B, n);
    mul(AB, A, B, n);
    transpose(AT, A, n);
    transpose(BT, B, n);
    mul(ATBT, AT, BT, n);
    fputmat(C, n, fout);
    fprintf(fout, "\n");
    fputmat(AB, n, fout);
    fprintf(fout, "\n");
    fputmat(ATBT, n, fout);

    fclose(fin);
    fclose(fout);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex4();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
