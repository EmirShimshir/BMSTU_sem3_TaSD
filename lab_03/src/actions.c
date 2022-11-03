#include <stdio.h>
#include <stdlib.h>

#include "../inc/actions.h"
#include "../inc/log.h"
#include "../inc/errors.h"

void generate_matrix_t(matrix_t *matrix)
{
    LOG_INFO("started");
    int row, column;

    for (int i = 0; i < matrix->non_zero; i++)
    {
        row = rand() % matrix->rows;
        column = rand() % matrix->columns;
        if (matrix->matrix[row][column] == 0)
            matrix->matrix[row][column] = 1 + rand() % 100;
        else
            i--;
    }

    LOG_INFO("finish successfully");
}

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

int read_params(int *rows, int *columns, int *non_zero)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    printf("Введите количество строк матрицы: ");
    // Ввод количества строк
    if (scanf("%d", rows) != 1)
    {
        int err = ERR_INPUT_ROWS;
        LOG_ERROR(err);
        return err;
    }

    if (*rows < 1)
    {
        int err = ERR_INPUT_ROWS;
        LOG_ERROR(err);
        return err;
    }

    printf("Введите количество столбцов матрицы: ");
    // Ввод количества столбцов
    if (scanf("%d", columns) != 1)
    {
        int err = ERR_INPUT_COLUMNS;
        LOG_ERROR(err);
        return err;
    }

    if (*columns < 1)
    {
        int err = ERR_INPUT_COLUMNS;
        LOG_ERROR(err);
        return err;
    }

    printf("Введите количество ненулевых элементов матрицы: ");
    // Ввод количества ненулевых элементов
    if (scanf("%d", non_zero) != 1)
    {
        int err = ERR_INPUT_NON_ZERO;
        LOG_ERROR(err);
        return err;
    }

    if (*non_zero < 1 || *non_zero > *rows * *columns)
    {
        int err = ERR_INPUT_NON_ZERO;
        LOG_ERROR(err);
        return err;
    }

    LOG_INFO("finish successfully");
    return err;
}

int read_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;
    int rows, columns, non_zero;

    err = read_params(&rows, &columns, &non_zero);
    if (err != EXIT_SUCCESS)
    {
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

int generate_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;
    int rows, columns, non_zero;

    err = read_params(&rows, &columns, &non_zero);
    if (err != EXIT_SUCCESS)
    {
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

    generate_matrix_t(matrix);

    fill_sparse_matrix_t_by_matrix_t(sparse_matrix, matrix);

    LOG_INFO("finish successfully");
    return err;
}

int count_non_zero(matrix_t *matrix_1, matrix_t *matrix_2)
{
    LOG_INFO("started");
    int non_zero = 0;

    for (int i = 0; i < matrix_1->rows; i++)
    {
        for (int j = 0; j < matrix_1->columns; j++)
        {
            if (matrix_1->matrix[i][j] != 0 || matrix_2->matrix[i][j] != 0)
            {
                LOG_DEBUG("matrix_1->matrix[i][j]: %d", matrix_1->matrix[i][j]);
                LOG_DEBUG("matrix_2->matrix[i][j]: %d", matrix_2->matrix[i][j]);
                non_zero++;
            }
        }
    }

    LOG_DEBUG("matrix_1->non_zero: %d", matrix_1->non_zero);
    LOG_DEBUG("matrix_2->non_zero: %d", matrix_2->non_zero);
    LOG_DEBUG("non_zero: %d", non_zero);

    return non_zero;
    LOG_INFO("finish successfully");
}

void addition(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *matrix_res)
{
    LOG_INFO("started");
    for (int i = 0; i < matrix_res->rows; i++)
        for (int j = 0; j < matrix_res->columns; j++)
            matrix_res->matrix[i][j] = matrix_1->matrix[i][j] + matrix_2->matrix[i][j];

    LOG_INFO("finish successfully");
}


int addition_matrix_t(matrix_t *matrix_1, matrix_t *matrix_2)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (matrix_1->matrix == NULL || matrix_2->matrix == NULL)
    {
        err = ERR_MATRIX_NOT_ALLOCATED;
        LOG_ERROR(err);
        return err;
    }

    if (matrix_1->rows != matrix_2->rows && matrix_1->columns != matrix_2->columns)
    {
        err = ERR_DIFF_MATRIX_SIZE;
        LOG_ERROR(err);
        return err;
    }

    matrix_t matrix_res;
    sparse_matrix_t sparse_matrix_res;
    int rows = matrix_1->rows;
    int columns = matrix_1->columns;
    int non_zero = count_non_zero(matrix_1, matrix_2);

    err = init_matrix_t(&matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    err = init_sparse_matrix_t(&sparse_matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    addition(matrix_1, matrix_2, &matrix_res);

    fill_sparse_matrix_t_by_matrix_t(&sparse_matrix_res, &matrix_res);

    print_matrix_t(&matrix_res);
    print_sparse_matrix_t(&sparse_matrix_res);

    free_sparse_matrix_t(&sparse_matrix_res);
    free_matrix_t(&matrix_res);

    LOG_INFO("finish successfully");
    return err;
}

void addition_sparse(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, sparse_matrix_t *sparse_matrix_res)
{
    LOG_INFO("started");

    sparse_matrix_res->non_zero = 0;
    sparse_matrix_res->IA[0] = 0;
    for (int row = 0; row < sparse_matrix_1->rows; row++)
    {
        int i, j, count_row = 0;
        for (i = sparse_matrix_1->IA[row], j = sparse_matrix_2->IA[row]; i < sparse_matrix_1->IA[row + 1] && j < sparse_matrix_2->IA[row + 1];)
        {
            LOG_DEBUG("sparse_matrix_1->IA[row]: %d", sparse_matrix_1->IA[row]);
            LOG_DEBUG("sparse_matrix_1->IA[row + 1]: %d", sparse_matrix_1->IA[row + 1]);
            LOG_DEBUG("sparse_matrix_2->IA[row]: %d", sparse_matrix_2->IA[row]);
            LOG_DEBUG("sparse_matrix_2->IA[row + 1]: %d", sparse_matrix_2->IA[row + 1]);
            LOG_DEBUG("i: %d", i);
            LOG_DEBUG("j: %d", j);
            LOG_DEBUG("sparse_matrix_1->JA[i]: %d", sparse_matrix_1->JA[i]);
            LOG_DEBUG("sparse_matrix_1->A[i]: %d", sparse_matrix_1->A[i]);
            LOG_DEBUG("sparse_matrix_2->JA[j]: %d", sparse_matrix_2->JA[j]);
            LOG_DEBUG("sparse_matrix_2->A[j]: %d", sparse_matrix_2->A[j]);

            if (sparse_matrix_1->JA[i] < sparse_matrix_2->JA[j])
            {
                sparse_matrix_res->A[sparse_matrix_res->non_zero] = sparse_matrix_1->A[i];
                sparse_matrix_res->JA[sparse_matrix_res->non_zero] = sparse_matrix_1->JA[i];
                count_row++;
                sparse_matrix_res->non_zero++;
                i++;
            }
            else if (sparse_matrix_1->JA[i] > sparse_matrix_2->JA[j])
            {
                sparse_matrix_res->A[sparse_matrix_res->non_zero] = sparse_matrix_2->A[j];
                sparse_matrix_res->JA[sparse_matrix_res->non_zero] = sparse_matrix_2->JA[j];
                count_row++;
                sparse_matrix_res->non_zero++;
                j++;
            }
            else
            {
                sparse_matrix_res->A[sparse_matrix_res->non_zero] = sparse_matrix_1->A[i] + sparse_matrix_2->A[j];
                sparse_matrix_res->JA[sparse_matrix_res->non_zero] = sparse_matrix_1->JA[i];
                count_row++;
                sparse_matrix_res->non_zero++;
                i++;
                j++;
            }
        }

        if (j == sparse_matrix_2->IA[row + 1])
        {
            for (; i < sparse_matrix_1->IA[row + 1];)
            {
                sparse_matrix_res->A[sparse_matrix_res->non_zero] = sparse_matrix_1->A[i];
                sparse_matrix_res->JA[sparse_matrix_res->non_zero] = sparse_matrix_1->JA[i];
                count_row++;
                sparse_matrix_res->non_zero++;
                i++;
            }
        }
        else if (i == sparse_matrix_1->IA[row + 1])
        {
            for (; j < sparse_matrix_2->IA[row + 1];)
            {
                sparse_matrix_res->A[sparse_matrix_res->non_zero] = sparse_matrix_2->A[j];
                sparse_matrix_res->JA[sparse_matrix_res->non_zero] = sparse_matrix_2->JA[j];
                count_row++;
                sparse_matrix_res->non_zero++;
                j++;
            }
        }
        sparse_matrix_res->IA[row + 1] = count_row + sparse_matrix_res->IA[row];
    }

    LOG_INFO("finish successfully");
}

int addition_sparse_matrix_t(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (sparse_matrix_1->A == NULL || sparse_matrix_2->A == NULL)
    {
        err = ERR_MATRIX_NOT_ALLOCATED;
        LOG_ERROR(err);
        return err;
    }

    if (sparse_matrix_1->rows != sparse_matrix_2->rows && sparse_matrix_1->columns != sparse_matrix_2->columns)
    {
        err = ERR_DIFF_MATRIX_SIZE;
        LOG_ERROR(err);
        return err;
    }

    sparse_matrix_t sparse_matrix_res;
    int rows = sparse_matrix_1->rows;
    int columns = sparse_matrix_1->columns;
    int non_zero = sparse_matrix_1->non_zero + sparse_matrix_2->non_zero;

    err = init_sparse_matrix_t(&sparse_matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    addition_sparse(sparse_matrix_1, sparse_matrix_2, &sparse_matrix_res);

    matrix_t matrix_res;
    err = init_matrix_t(&matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

//    fill_matrix_t_by_sparse_matrix_t(&sparse_matrix_res, &matrix_res);

    print_matrix_t(&matrix_res);
    print_sparse_matrix_t(&sparse_matrix_res);

    free_sparse_matrix_t(&sparse_matrix_res);
    free_matrix_t(&matrix_res);

    LOG_INFO("finish successfully");
    return err;
}

//74 69 46 0 0 26 88
//22 0 0 100 83 80 66
//36 24 54 99 0 0 0
//0 54 97 89 36 0 0
//0 0 0 4 95 0 31
//50 58 30 0 0 0 95
//94 0 100 0 95 14 73
//
//A:  74 69 46 26 88 22 100 83 80 66 36 24 54 99 54 97 89 36 4 95 31 50 58 30 95 94 100 95 14 73
//JA: 0 1 2 5 6 0 3 4 5 6 0 1 2 3 1 2 3 4 3 4 6 0 1 2 6 0 2 4 5 6
//IA: 0 5 10 14 18 21 25 30
//
//0 0 0 0 16 43 19
//67 85 69 0 39 96 2
//95 0 12 24 26 0 0
//73 0 0 53 90 48 0
//12 69 0 51 36 0 0
//0 99 0 91 0 0 0
//14 86 39 27 62 54 73
//
//A:  16 43 19 67 85 69 39 96 2 95 12 24 26 73 53 90 48 12 69 51 36 99 91 14 86 39 27 62 54 73
//JA: 4 5 6 0 1 2 4 5 6 0 2 3 4 0 3 4 5 0 1 3 4 1 3 0 1 2 3 4 5 6
//IA: 0 3 9 13 17 21 23 30
//
//сумма в стандарте
//74 69 46 0 16 69 107
//89 85 69 100 122 176 68
//131 24 66 123 26 0 0
//73 54 97 142 126 48 0
//12 69 0 55 131 0 31
//50 157 30 91 0 0 95
//108 86 139 27 157 68 146
//
//A:  74 69 46 16 69 107 89 85 69 100 122 176 68 131 24 66 123 26 73 54 97 142 126 48 12 69 55 131 31 50 157 30 91 95 108 86 139 27 157 68 146
//JA: 0 1 2 4 5 6 0 1 2 3 4 5 6 0 1 2 3 4 0 1 2 3 4 5 0 1 3 4 6 0 1 2 3 6 0 1 2 3 4 5 6
//IA: 0 6 13 18 24 29 34 41
//
//сумма в разряженной
//
//A:  74 69 46 16 69 107 89 85 69 100 122 176 68 131 24 66 123 26 73 73 54 97 142 126 48 12 12 69 55 131 31 50 157 30 91 95 108 86 139 27 157 68 146
//JA: 0 1 2 4 5 6 0 1 2 3 4 5 6 0 1 2 3 4 0 0 1 2 3 4 5 0 0 1 3 4 6 0 1 2 3 6 0 1 2 3 4 5 6
//IA: 0 6 13 19 26 31 36 43
//
//
//
//
//
//0 0 0 0 0
//0 0 0 0 0
//0 0 88 0 74
//73 0 0 0 0
//66 0 0 24 0
//
//A:  88 74 73 66 24
//JA: 2 4 0 0 3
//IA: 0 0 0 2 3 5
//
//0 0 4 100 0
//0 0 0 0 0
//0 0 0 0 0
//0 36 30 0 0
//0 0 0 0 58
//
//A:  4 100 36 30 58
//JA: 2 3 1 2 4
//IA: 0 2 2 2 4 5
//
//сумма в стандарте
//
//0 0 4 100 0
//0 0 0 0 0
//0 0 88 0 74
//73 36 30 0 0
//66 0 0 24 58
//
//A:  4 100 88 74 73 36 30 66 24 58
//JA: 2 3 2 4 0 1 2 0 3 4
//IA: 0 2 2 4 7 10
//
//A:  88 74 73 36 66 24 58
//JA: 2 4 0 1 0 3 4
//IA: 0 0 0 2 4 7
