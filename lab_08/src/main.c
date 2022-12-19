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

int matrix_read_file(FILE *f, matrix_t *matrix)
{
    if (fscanf(f, "%d", &matrix->count) != 1 || matrix->count < 1)
        return 1;

    if (allocate_matrix(matrix))
        return 1;

    for (int i = 0; i < matrix->count; i++)
        for (int j = 0; j < matrix->count; j++)
            if (fscanf(f, "%d", &matrix->data[i][j]) != 1)
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
    matrix_t graph_a;
    graph_a.data = NULL;
    matrix_t graph_b;
    graph_b.data = NULL;
    FILE *f;

    f = fopen("./data/3_a.txt", "r");
    if (matrix_read_file(f, &graph_a))
        return 1;
    fclose(f);

    f = fopen("./data/3_b.txt", "r");
    if (matrix_read_file(f, &graph_b))
        return 1;
    fclose(f);

    matrix_print(graph_a);
    matrix_print(graph_b);

    free_matrix(&graph_a);
    free_matrix(&graph_b);

    return 0;
}