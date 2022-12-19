#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int count;
    int **data;
} matrix_t;

void free_matrix(matrix_t *matrix)
{
    if (matrix->data != NULL)
    {
        for (int i = 0; i < matrix->count; i++)
            free(matrix->data[i]);

        free(matrix->data);
        matrix->data = NULL;
    }
}

int allocate_matrix(matrix_t *matrix)
{
    matrix->data = calloc(matrix->count, sizeof(*matrix->data));
    if (matrix->data == NULL)
        return 1;

    for (int i = 0; i < matrix->count; i++)
    {
        matrix->data[i] = malloc(matrix->count * sizeof(**matrix->data));
        if (matrix->data[i] == NULL)
        {
            free_matrix(matrix);
            return 1;
        }
    }

    return 0;
}

int matrix_fill(matrix_t *matrix, int count)
{
    matrix->count = count;

    if (allocate_matrix(matrix))
        return 1;

    for (int i = 0; i < matrix->count; i++)
        for (int j = 0; j < matrix->count; j++)
            if (scanf("%d", &matrix->data[i][j]) != 1)
            {
                free_matrix(matrix);
                return 1;
            }

    return 0;
}

void matrix_print(matrix_t matrix)
{
    for (int i = 0; i < matrix.count; i++)
    {
        for (int j = 0; j < matrix.count; j++)
            printf("%d ", matrix.data[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int count;

    matrix_t graph_a;
    graph_a.data = NULL;
    matrix_t graph_b;
    graph_b.data = NULL;


    if (scanf("%d", &count) != 1 || count < 1)
        return 1;

    if (matrix_fill(&graph_a, count))
        return 1;

    if (matrix_fill(&graph_b, count))
        return 1;

    matrix_print(graph_a);
    matrix_print(graph_b);

    free_matrix(&graph_a);
    free_matrix(&graph_b);

    return 0;
}