#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct
{
    int count;
    int **data;
} matrix_t;

matrix_t *create_matrix(int count);
int **allocate_matrix(int count);
void free_matrix(int **data, int count);
int check_empty_matrix(matrix_t *graph);
int check_graph_null(matrix_t *graph);

#endif // __GRAPH_H__
