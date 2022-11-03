#ifndef __MATRIX_H__

#define __MATRIX_H__

typedef struct
{
    int rows;
    int columns;
    int non_zero;

    int **matrix;
} matrix_t;

void free_matrix(int **matrix, int rows);
int **allocate_matrix(int rows, int columns);
int init_matrix_t(matrix_t *matrix, int rows, int columns, int non_zero);
void free_matrix_t(matrix_t *matrix);
void print_matrix_t(matrix_t *matrix);

#endif // __MATRIX_H__
