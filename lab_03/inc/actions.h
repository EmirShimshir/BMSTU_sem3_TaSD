#ifndef __ACTIONS_H__

#define __ACTIONS_H__

#include "matrix.h"
#include "sparse_matrix.h"


int generate_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);
void generate_matrix_t(matrix_t *matrix);

int print_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);

int read_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);
int read_matrix_t(matrix_t *matrix);
void fill_sparse_matrix_t_by_matrix_t(sparse_matrix_t *sparse_matrix, matrix_t *matrix);

int addition_matrix_t(matrix_t *matrix_1, matrix_t *matrix_2);
int count_non_zero(matrix_t *matrix_1, matrix_t *matrix_2);
void addition(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *matrix_res);

int addition_sparse_matrix_t(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2);
void addition_sparse(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, sparse_matrix_t *sparse_matrix_res);

#endif // __ACTIONS_H__