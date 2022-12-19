#include <stdlib.h>
#include <stdio.h>

#include "../inc/graph.h"
#include "../inc/errors.h"

matrix_t *create_matrix(int count)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));
    if (matrix)
    {
        matrix->count = count;
        matrix->data = allocate_matrix(count);
        if (matrix->data == NULL)
        {
            free(matrix);
            matrix = NULL;
        }
    }

    return matrix;
}

double **allocate_matrix(int count)
{
    double **data = calloc(count, sizeof(double*));
    if (data)
        for (int i = 0; i < count; ++i)
        {
            data[i] = calloc(count, sizeof(double));
            if (!data[i])
            {
                free_matrix(data, count);
                data = NULL;
            }
        }

    return data;
}

void free_matrix(double **data, int count)
{
    for (int i = 0; i < count; ++i)
        free(data[i]);

    free(data);
}

int check_empty_matrix(matrix_t *graph)
{
    if (graph->data == NULL)
    {
        printf("Ошибка, данные не загружены\n");
        return GRAPH_ERR;
    }

    return EXIT_SUCCESS;
}

int check_graph_null(matrix_t *graph)
{
    if (graph == NULL)
    {
        printf("Ошибка, граф - NULL\n");
        return GRAPH_ERR;
    }

    return EXIT_SUCCESS;
}
