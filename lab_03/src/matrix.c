#include <stdio.h>
#include <stdlib.h>

#include "../inc/matrix.h"
#include "../inc/log.h"
#include "../inc/errors.h"

void free_matrix(int **matrix, int rows)
{
    LOG_INFO("started");
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    LOG_INFO("finish successfully");
}

int **allocate_matrix(int rows, int columns)
{
    LOG_INFO("started");
    int **matrix = malloc(rows * sizeof(int*));
    if (matrix == NULL)
    {
        LOG_DEBUG("%s", "error malloc(n * sizeof(int*))");
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = calloc(columns, sizeof(int));
        if (matrix[i] == NULL)
        {
            free_matrix(matrix, i);
            LOG_DEBUG("%s", "error calloc(columns, sizeof(int))");
            return NULL;
        }
    }
    LOG_INFO("finish successfully");
    return matrix;
}

int init_matrix_t(matrix_t *matrix, int rows, int columns, int non_zero)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    matrix->rows = rows;
    matrix->columns = columns;
    matrix->non_zero = non_zero;

    matrix->matrix = allocate_matrix(rows, columns);

    if (matrix->matrix == NULL)
    {
        LOG_ERROR(ERR_MEM_ALLOC);
        err = ERR_MEM_ALLOC;
        return err;
    }

    LOG_INFO("finish successfully");
    return err;
}

void free_matrix_t(matrix_t *matrix)
{
    LOG_INFO("started");
    free_matrix(matrix->matrix, matrix->rows);
    matrix->matrix = NULL;
    matrix->rows = 0;
    matrix->columns = 0;
    matrix->non_zero = 0;
    LOG_INFO("finish successfully");
}

void print_matrix_t(matrix_t *matrix)
{
    LOG_INFO("started");
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
    LOG_INFO("finish successfully");
}