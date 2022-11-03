#include <stdlib.h>

#include "../inc/sparse_matrix.h"
#include "../inc/log.h"
#include "../inc/errors.h"


int init_sparse_matrix_t(sparse_matrix_t *matrix, int rows, int columns, int non_zero)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    matrix->rows = rows;
    matrix->columns = columns;
    matrix->non_zero = non_zero;

    matrix->A = malloc(matrix->non_zero * sizeof(int));
    if (!matrix->A)
    {
        err = ERR_MEM_ALLOC;
        LOG_ERROR(err);
        return err;
    }

    matrix->JA = malloc(matrix->non_zero * sizeof(int));
    if (!matrix->rows)
    {
        err = ERR_MEM_ALLOC;
        LOG_ERROR(err);
        return err;
    }

    matrix->IA = malloc((matrix->rows + 1) * sizeof(int));
    if (!matrix->columns)
    {
        err = ERR_MEM_ALLOC;
        LOG_ERROR(err);
        return err;
    }

    return err;
    LOG_INFO("finish successfully");
}

void free_sparse_matrix_t(sparse_matrix_t *matrix)
{
    LOG_INFO("started");
    free(matrix->A);
    free(matrix->JA);
    free(matrix->IA);
    matrix->A = NULL;
    matrix->JA = NULL;
    matrix->IA = NULL;
    matrix->rows = 0;
    matrix->columns = 0;
    matrix->non_zero = 0;
    LOG_INFO("finish successfully");
}

void print_sparse_matrix_t(sparse_matrix_t *sparse_matrix)
{
    printf("A:  ");
    for (int i = 0; i < sparse_matrix->non_zero; i++)
        printf("%d ", sparse_matrix->A[i]);
    printf("\n");

    printf("JA: ");
    for (int i = 0; i < sparse_matrix->non_zero; i++)
        printf("%d ", sparse_matrix->JA[i]);
    printf("\n");

    printf("IA: ");
    for (int i = 0; i < sparse_matrix->rows + 1; i++)
        printf("%d ", sparse_matrix->IA[i]);
    printf("\n");
}