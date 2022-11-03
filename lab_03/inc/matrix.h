#ifndef __MATRIX_H__

#define __MATRIX_H__

typedef struct matrix_t
{
    int rows;
    int columns;
    int non_zero;

    int **matrix;
} matrix_t;

void destroy(matrix_t matrix);
matrix_t create(int row, int column);
void matrix_print(matrix_t matrix);

#endif // __MATRIX_H__
