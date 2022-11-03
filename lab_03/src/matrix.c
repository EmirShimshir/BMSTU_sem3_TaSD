#include <stdio.h>
#include <stdlib.h>

#include "../inc/matrix.h"
#include "../inc/log.h"
#include "../inc/errors.h"

void destroy_matrix(matrix_t matrix)
{
    LOG_INFO("start");
    if (matrix != NULL)
    {
        free(matrix->matrix[0]);
        free(matrix->matrix);
        free(matrix);
        matrix = NULL;
    }

    LOG_INFO("finish successfully");
}

matrix_t create_matrix(int row, int column, non_zero)
{
    LOG_INFO("start");

    matrix_t matrix = malloc(sizeof(struct matrix_type));
    if (matrix == NULL)
    {
        LOG_DEBUG("error malloc(sizeof(struct matrix_type))");
        return NULL;
    }
    printf("%lu\n", sizeof(*matrix));

    matrix->row = row;
    matrix->column = column;

    matrix->matrix = malloc(matrix->row *sizeof(*matrix->matrix));
    if (matrix->matrix == NULL)
    {
        LOG_DEBUG("error malloc(matrix->row, sizeof(*matrix->matrix))");
        free(matrix);
        return NULL;
    }
    printf("%lu\n", sizeof(*matrix->matrix));

    int *data = malloc(matrix->row * matrix->column * sizeof(**matrix->matrix));
    if (data == NULL)
    {
        LOG_DEBUG("error malloc(matrix->row * matrix->column * sizeof(**matrix->matrix))");
        free(matrix->matrix);
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < matrix->row; i++)
        matrix->matrix[i] = data + i * matrix->column;

    LOG_INFO("finish successfully");
    return matrix;
}

void matrix_print(matrix_t matrix)
{
    LOG_INFO("started");
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
        {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
    LOG_INFO("finish successfully");
}

