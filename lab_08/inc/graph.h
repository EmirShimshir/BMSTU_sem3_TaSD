#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct
{
    int count;
    int **data;
} matrix_t;

/*
* Функция создает матрицу смежности
*
* Принимает количетсво вершин
*/
matrix_t *create_matrix(int count);

/*
* Функция выделяет память для матрицы смежности
*
* Принимает количетсво вершин
*/
int **allocate_matrix(int count);

/*
* Функция освобождает память для матрицы смежности
*
* Принимает количетсво вершин и матрицу
*/
void free_matrix(int **data, int count);

int check_empty_matrix(matrix_t *graph);
int check_graph_null(matrix_t *graph);

#endif // __GRAPH_H__
