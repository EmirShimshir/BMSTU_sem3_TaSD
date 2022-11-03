#ifndef __ACTIONS_H__

#define __ACTIONS_H__

#include "matrix.h"
#include "sparse_matrix.h"


//int generate_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);
int print_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);

int read_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);
int read_matrix_t(matrix_t *matrix);
void fill_sparse_matrix_t_by_matrix_t(sparse_matrix_t *sparse_matrix, matrix_t *matrix);

#endif // __ACTIONS_H__