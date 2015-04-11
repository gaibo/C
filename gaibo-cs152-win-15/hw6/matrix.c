/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 6 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


matrix* matrix_zero(int n_rows, int n_cols) {
    // allocating the matrix while filling it with zeroes
    matrix* mat_out = malloc(sizeof(matrix));
    mat_out->n_rows = n_rows;
    mat_out->n_cols = n_cols;
    
    int i_row, i_col;
    mat_out->entries = malloc(n_rows * sizeof(float*));
    for (i_row = 0; i_row < n_rows; i_row++) {
        mat_out->entries[i_row] = malloc(n_cols * sizeof(float));
        for (i_col = 0; i_col < n_cols; i_col++) {
            mat_out->entries[i_row][i_col] = 0.0;
        }
    }
    
    return mat_out;
}

float matrix_read(matrix* m, unsigned int i, unsigned int j) {
    // error if i or j is out of bounds
    if (i >= m->n_rows || j >= m->n_cols) {
        fprintf(stderr, \
            "error matrix_read: row or column is outside of matrix\n");
        exit(1);
    }
    
    return m->entries[i][j];
}

void matrix_write(matrix* m, unsigned int i, unsigned int j, float x) {
    // error if i or j is out of bounds
    if (i >= m->n_rows || j >= m->n_cols) {
        fprintf(stderr, \
            "error matrix_write: row or column is outside of matrix\n");
        exit(1);
    }
    
    m->entries[i][j] = x;
    return;
}

matrix* matrix_add(matrix* m, matrix* n) {
    // check dimensions
    if (m->n_rows != n->n_rows || m->n_cols != n->n_cols) {
        fprintf(stderr, "error matrix_add: differing dimensions\n");
        exit(1);
    }
    
    unsigned int n_rows = m->n_rows;
    unsigned int n_cols = m->n_cols;
    matrix* mat_out = matrix_zero(n_rows, n_cols);
    
    int i_row, i_col;
    for (i_row = 0; i_row < n_rows; i_row++) {
        for (i_col = 0; i_col < n_cols; i_col++) {
            matrix_write(mat_out, i_row, i_col, \
                matrix_read(m, i_row, i_col) + matrix_read(n, i_row, i_col));
        }
    }
    
    return mat_out;
}

matrix* matrix_mult(matrix* m, matrix* n) {
    // check dimensions
    if (m->n_cols != n->n_rows) {
        fprintf(stderr, "error matrix_mult: dimensions issue\n");
        exit(1);
    }
    
    unsigned int n_rows = m->n_rows;
    unsigned int n_cols = n->n_cols;
    unsigned int inner_limit = m->n_cols;  // same as n->n_rows
    matrix* mat_out = matrix_zero(n_rows, n_cols);
    
    int i_row, i_col, i_inner;
    float acc;
    for (i_row = 0; i_row < n_rows; i_row++) {
        for (i_col = 0; i_col < n_cols; i_col++) {
            acc = 0.0;
            for (i_inner = 0; i_inner < inner_limit; i_inner++) {
                acc += matrix_read(m, i_row, i_inner) \
                       * matrix_read(n, i_inner, i_col);
            }
            matrix_write(mat_out, i_row, i_col, acc);
        }
    }
    
    return mat_out;
}

void matrix_show(matrix* m) {
    int i_row, i_col;
    for (i_row = 0; i_row < m->n_rows; i_row++) {
        for (i_col = 0; i_col < m->n_cols; i_col++) {
            printf("%f ", matrix_read(m, i_row, i_col));
        }
        printf("\n");
    }
    return;
}

void matrix_free(matrix* m) {
    int i_row;
    for (i_row = 0; i_row < m->n_rows; i_row++) {
        free(m->entries[i_row]);
    }
    free(m->entries);
    free(m);
    return;
}