#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct matrix matrix;
struct matrix {
    unsigned int n_rows;
    unsigned int n_cols;
    float **entries;
};

/* matrix_zero : int, int -> matrix*    */
/* - build a matrix of given dimension, */
/*   all entries 0.0                    */
matrix *matrix_zero(int n_rows, int n_cols);

/* matrix_read : matrix*, unsigned int, unsigned int -> float      */
/* - read the item at row i, column j            */
/* - error if row, column are outside the matrix */
float matrix_read(matrix *m, unsigned int i, unsigned int j);

/* matrix_write : matrix*, unsigned int, unsigned int, float -> [void] */
/* - write the float values to the location          */
/* - error if row, column are outside the matrix     */
void matrix_write(matrix *m, unsigned int i, unsigned int j, float x);

/* matrix_add : matrix*, matrix* -> matrix* */
/* - add two matrices non-destructively     */
/*   (i.e., construct a new matrix)         */
/* - error if matrices' dimensions differ   */
matrix *matrix_add(matrix *m, matrix *n);

/* matrix_mult : matrix*, matrix* -> matrix*                  */
/* - multiply two matrices, constructing a new matrix         */
/* - error if dimensions don't allow matrix multiplication    */
/* - note: this is matrix multiplication, not pairwise product */
matrix *matrix_mult(matrix *m, matrix *n);

/* matrix_show : matrix* -> [void] */
void matrix_show(matrix *m);

/* matrix_free : matrix* -> [void] */
void matrix_free(matrix *m);

#endif /* _MATRIX_H */