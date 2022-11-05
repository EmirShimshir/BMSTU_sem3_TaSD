#ifndef __ACTIONS_H__

#define __ACTIONS_H__

#include "matrix.h"
#include "sparse_matrix.h"

/*
* Функция заполняет матрицы с заданными параметрами случайными числами.
*
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
*/
int generate_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);
void generate_matrix_t(matrix_t *matrix);

/*
* Функция выводит матрицу на экран
*
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
*/
int print_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);

/*
* Функция заполнет матрицы элементами, введенными пользователем
*
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
*/
int read_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);
int read_matrix_t(matrix_t *matrix);

/*
* Функция заполняет матрицу в разряежнной форме по данным из матрицы
* в стандартной форме
*
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
*/
void fill_sparse_matrix_t_by_matrix_t(sparse_matrix_t *sparse_matrix, matrix_t *matrix);

/*
* Функция заполняет матрицу в стандартной форме по данным из матрицы
* в разряежнной форме
*
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
*/
void fill_matrix_t_by_sparse_matrix_t(sparse_matrix_t *sparse_matrix, matrix_t *matrix);

/*
* Функция складывает матрицы в стандартной форме
*
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
* Принимает указатель на структуру, хранящую матрицу в стандартном формате
*/
int addition_matrix_t(matrix_t *matrix_1, matrix_t *matrix_2);
int count_non_zero(matrix_t *matrix_1, matrix_t *matrix_2);
void addition(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *matrix_res);

/*
* Функция складывает матрицы в разряженном формате
*
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
* Принимает указатель на структуру, хранящую матрицу в разряженном формате
*/
int addition_sparse_matrix_t(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2);
int count_non_zero_sparse(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2);
void addition_sparse(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, sparse_matrix_t *sparse_matrix_res);

int compare_addition(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, matrix_t *matrix_1, matrix_t *matrix_2);
unsigned long long microseconds_now(void);

#endif // __ACTIONS_H__