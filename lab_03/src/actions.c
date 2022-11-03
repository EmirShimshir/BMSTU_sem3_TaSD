#include <stdio.h>

#include "../inc/actions.h"
#include "../inc/log.h"
#include "../inc/errors.h"

int read_matrix_t(matrix_t *matrix)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;
    int index_row, index_column;

    printf("Ввод ненулевых элементов (индексы начинаются с 0)\n");
    for (int i = 0; i < matrix->non_zero; i++)
    {
        printf("Введите индекс строки %d элемента: ", i + 1);
        if (scanf("%d", &index_row) != 1)
        {
            int err = ERR_INPUT_ROWS;
            LOG_ERROR(err);
            return err;
        }
        if (index_row < 0 || index_row >= matrix->rows)
        {
            int err = ERR_INPUT_ROWS;
            LOG_ERROR(err);
            return err;
        }

        printf("Введите индекс столбца %d элемента: ", i + 1);
        if (scanf("%d", &index_column) != 1)
        {
            int err = ERR_INPUT_COLUMNS;
            LOG_ERROR(err);
            return err;
        }
        if (index_column < 0 || index_column >= matrix->columns)
        {
            int err = ERR_INPUT_COLUMNS;
            LOG_ERROR(err);
            return err;
        }

        printf("Введите значение %d элемента: ", i + 1);
        if (scanf("%d", &matrix->matrix[index_row][index_column]) != 1)
        {
            int err = ERR_INPUT_ELEM;
            LOG_ERROR(err);
            return err;
        }
    }

    LOG_INFO("finish successfully");
    return err;
}

void fill_sparse_matrix_t_by_matrix_t(sparse_matrix_t *sparse_matrix, matrix_t *matrix)
{
    LOG_INFO("started");
    sparse_matrix->IA[0] = 0;
    int index_A = 0;
    int count_row = 0;

    for (int i = 0; i < matrix->rows; i++)
    {
        count_row = 0;
        for (int j = 0; j < matrix->columns; j++)
        {
            if (matrix->matrix[i][j] != 0)
            {
                sparse_matrix->A[index_A] = matrix->matrix[i][j];
                sparse_matrix->JA[index_A] = j;
                index_A++;
                count_row++;
            }
        }
        sparse_matrix->IA[i + 1] = count_row + sparse_matrix->IA[i];
    }
    LOG_INFO("finish successfully");
}

int read_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;
    int rows, columns, non_zero;

    printf("Введите количество строк матрицы: ");
    // Ввод количества строк
    if (scanf("%d", &rows) != 1)
    {
        int err = ERR_INPUT_ROWS;
        LOG_ERROR(err);
        return err;
    }

    if (rows < 1)
    {
        int err = ERR_INPUT_ROWS;
        LOG_ERROR(err);
        return err;
    }

    printf("Введите количество столбцов матрицы: ");
    // Ввод количества столбцов
    if (scanf("%d", &columns) != 1)
    {
        int err = ERR_INPUT_COLUMNS;
        LOG_ERROR(err);
        return err;
    }

    if (columns < 1)
    {
        int err = ERR_INPUT_COLUMNS;
        LOG_ERROR(err);
        return err;
    }

    printf("Введите количество ненулевых элементов матрицы: ");
    // Ввод количества ненулевых элементов
    if (scanf("%d", &non_zero) != 1)
    {
        int err = ERR_INPUT_NON_ZERO;
        LOG_ERROR(err);
        return err;
    }

    if (non_zero < 1 || non_zero > rows * columns)
    {
        int err = ERR_INPUT_NON_ZERO;
        LOG_ERROR(err);
        return err;
    }

    free_matrix_t(matrix);
    err = init_matrix_t(matrix, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    free_sparse_matrix_t(sparse_matrix);
    err = init_sparse_matrix_t(sparse_matrix, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    err = read_matrix_t(matrix);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    fill_sparse_matrix_t_by_matrix_t(sparse_matrix, matrix);

    LOG_INFO("finish successfully");
    return err;
}

int print_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    printf("Введите вид матрицы (0 - стандартный, 1 - разряженный): ");

    int print_method;
    if (scanf("%d", &print_method) != 1)
    {
        int err = ERR_INPUT_PRINT_METHOD;
        LOG_ERROR(err);
        return err;
    }

    if (print_method != 1 && print_method != 0)
    {
        int err = ERR_INPUT_PRINT_METHOD;
        LOG_ERROR(err);
        return err;
    }

    if (print_method == 0)
        print_matrix_t(matrix);
    else
        print_sparse_matrix_t(sparse_matrix);



    LOG_INFO("finish successfully");
    return err;
}