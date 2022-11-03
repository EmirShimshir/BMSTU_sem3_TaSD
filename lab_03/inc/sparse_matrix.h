#ifndef __SPARSE_MATRIX_H__

#define __SPARSE_MATRIX_H__

typedef struct
{
    int rows;
    int columns;
    int non_zero;

    int *A;
    int *IA;
    int *JA;
} sparse_matrix_t;

int init_sparse_matrix_t(sparse_matrix_t *matrix, int rows, int columns, int nonzero_num);
void free_sparse_matrix_t(sparse_matrix_t *sparse_matrix);
void print_sparse_matrix_t(sparse_matrix_t *sparse_matrix);

#endif // __SPARSE_MATRIX_H__