#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

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
            matrix->matrix[row][column] = 1 + rand() % 9;
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

    if (sparse_matrix->A == NULL || matrix->matrix == NULL)
    {
        err = ERR_MATRIX_NOT_ALLOCATED;
        LOG_ERROR(err);
        return err;
    }

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

    printf("Результат сложения неразряженных матриц\n");
    printf("Результирующая матрица в стандартном виде:\n");
    print_matrix_t(&matrix_res);
    printf("Результирующая матрица в разряженном виде:\n");
    print_sparse_matrix_t(&sparse_matrix_res);

    free_sparse_matrix_t(&sparse_matrix_res);
    free_matrix_t(&matrix_res);

    LOG_INFO("finish successfully");
    return err;
}

void addition_sparse(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, sparse_matrix_t *sparse_matrix_res)
{
    LOG_INFO("started");

    int non_zero = 0;
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
                sparse_matrix_res->A[non_zero] = sparse_matrix_1->A[i];
                sparse_matrix_res->JA[non_zero] = sparse_matrix_1->JA[i];
                count_row++;
                non_zero++;
                i++;
            }
            else if (sparse_matrix_1->JA[i] > sparse_matrix_2->JA[j])
            {
                sparse_matrix_res->A[non_zero] = sparse_matrix_2->A[j];
                sparse_matrix_res->JA[non_zero] = sparse_matrix_2->JA[j];
                count_row++;
                non_zero++;
                j++;
            }
            else
            {
                sparse_matrix_res->A[non_zero] = sparse_matrix_1->A[i] + sparse_matrix_2->A[j];
                sparse_matrix_res->JA[non_zero] = sparse_matrix_1->JA[i];
                count_row++;
                non_zero++;
                i++;
                j++;
            }
        }

        if (j == sparse_matrix_2->IA[row + 1])
        {
            for (; i < sparse_matrix_1->IA[row + 1];)
            {
                sparse_matrix_res->A[non_zero] = sparse_matrix_1->A[i];
                sparse_matrix_res->JA[non_zero] = sparse_matrix_1->JA[i];
                count_row++;
                non_zero++;
                i++;
            }
        }
        else if (i == sparse_matrix_1->IA[row + 1])
        {
            for (; j < sparse_matrix_2->IA[row + 1];)
            {
                sparse_matrix_res->A[non_zero] = sparse_matrix_2->A[j];
                sparse_matrix_res->JA[non_zero] = sparse_matrix_2->JA[j];
                count_row++;
                non_zero++;
                j++;
            }
        }
        sparse_matrix_res->IA[row + 1] = count_row + sparse_matrix_res->IA[row];
    }

    LOG_DEBUG("sparse_matrix_res->non_zero: %d", sparse_matrix_res->non_zero);
    LOG_DEBUG("non_zero: %d", non_zero);

    LOG_INFO("finish successfully");
}

int count_non_zero_sparse(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2)
{
    LOG_INFO("started");
    int non_zero = 0;

    for (int row = 0; row < sparse_matrix_1->rows; row++)
    {
        int i, j;
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
                non_zero++;
                i++;
            }
            else if (sparse_matrix_1->JA[i] > sparse_matrix_2->JA[j])
            {
                non_zero++;
                j++;
            }
            else
            {
                non_zero++;
                i++;
                j++;
            }
        }

        if (j == sparse_matrix_2->IA[row + 1])
        {
            for (; i < sparse_matrix_1->IA[row + 1];)
            {
                non_zero++;
                i++;
            }
        }
        else if (i == sparse_matrix_1->IA[row + 1])
        {
            for (; j < sparse_matrix_2->IA[row + 1];)
            {
                non_zero++;
                j++;
            }
        }
    }

    LOG_INFO("finish successfully");
    return non_zero;
}

void fill_matrix_t_by_sparse_matrix_t(sparse_matrix_t *sparse_matrix, matrix_t *matrix)
{
    LOG_INFO("started");
    for (int row = 0; row < sparse_matrix->rows; row++)
    {
        for (int i = sparse_matrix->IA[row]; i < sparse_matrix->IA[row + 1]; i++)
        {
            matrix->matrix[row][sparse_matrix->JA[i]] = sparse_matrix->A[i];
        }
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
    int non_zero = count_non_zero_sparse(sparse_matrix_1, sparse_matrix_2);

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

    fill_matrix_t_by_sparse_matrix_t(&sparse_matrix_res, &matrix_res);

    printf("Результат сложения разряженных матриц\n");
    printf("Результирующая матрица в стандартном виде:\n");
    print_matrix_t(&matrix_res);
    printf("Результирующая матрица в разряженном виде:\n");
    print_sparse_matrix_t(&sparse_matrix_res);

    free_sparse_matrix_t(&sparse_matrix_res);
    free_matrix_t(&matrix_res);

    LOG_INFO("finish successfully");
    return err;
}

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}

int compare_addition(sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, matrix_t *matrix_1, matrix_t *matrix_2)
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

    sparse_matrix_t sparse_matrix_res;
    matrix_t matrix_res;
    int rows, columns, non_zero;

    rows = sparse_matrix_1->rows;
    columns = sparse_matrix_1->columns;
    non_zero = count_non_zero_sparse(sparse_matrix_1, sparse_matrix_2);

    err = init_sparse_matrix_t(&sparse_matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }
    unsigned long long beg_sparse_matrix, end_sparse_matrix, res_sparse_matrix;

    beg_sparse_matrix = microseconds_now();
    addition_sparse(sparse_matrix_1, sparse_matrix_2, &sparse_matrix_res);
    end_sparse_matrix = microseconds_now();
    res_sparse_matrix = end_sparse_matrix - beg_sparse_matrix;

    err = init_matrix_t(&matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    fill_matrix_t_by_sparse_matrix_t(&sparse_matrix_res, &matrix_res);

//    printf("Результат сложения разряженных матриц\n");
//    printf("Результирующая матрица в стандартном виде:\n");
//    print_matrix_t(&matrix_res);
//    printf("Результирующая матрица в разряженном виде:\n");
//    print_sparse_matrix_t(&sparse_matrix_res);

    int mem_sparse_matrix_1 = 2 * (sizeof(int) * sparse_matrix_1->non_zero) + sizeof(int) * (sparse_matrix_1->rows + 1);
    int mem_sparse_matrix_2 = 2 * (sizeof(int) * sparse_matrix_2->non_zero) + sizeof(int) * (sparse_matrix_2->rows + 1);
    int mem_sparse_matrix_res = 2 * (sizeof(int) * sparse_matrix_res.non_zero) + sizeof(int) * (sparse_matrix_res.rows + 1);
    int mem_sum_sparse = mem_sparse_matrix_1 + mem_sparse_matrix_2 + mem_sparse_matrix_res;
    int sparse_rows = sparse_matrix_res.rows;
    int sparse_columns = sparse_matrix_res.columns;
    int sparse_matrix_1_non_zero = sparse_matrix_1->non_zero;
    int sparse_matrix_2_non_zero = sparse_matrix_2->non_zero;
    int sparse_matrix_res_non_zero = sparse_matrix_res.non_zero;

    free_sparse_matrix_t(&sparse_matrix_res);
    free_matrix_t(&matrix_res);

    rows = matrix_1->rows;
    columns = matrix_1->columns;
    non_zero = count_non_zero(matrix_1, matrix_2);

    err = init_matrix_t(&matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    unsigned long long beg_matrix, end_matrix, res_matrix;

    beg_matrix = microseconds_now();
    addition(matrix_1, matrix_2, &matrix_res);
    end_matrix = microseconds_now();
    res_matrix = end_matrix - beg_matrix;

    err = init_sparse_matrix_t(&sparse_matrix_res, rows, columns, non_zero);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    fill_sparse_matrix_t_by_matrix_t(&sparse_matrix_res, &matrix_res);

//    printf("Результат сложения неразряженных матриц\n");
//    printf("Результирующая матрица в стандартном виде:\n");
//    print_matrix_t(&matrix_res);
//    printf("Результирующая матрица в разряженном виде:\n");
//    print_sparse_matrix_t(&sparse_matrix_res);

    int mem_matrix_1 = (sizeof(int) * matrix_1->rows * matrix_1->columns) + (matrix_1->rows * sizeof(int*));
    int mem_matrix_2 = (sizeof(int) * matrix_2->rows * matrix_2->columns) + (matrix_2->rows * sizeof(int*));
    int mem_matrix_res = (sizeof(int) * matrix_res.rows * matrix_res.columns) + (matrix_res.rows * sizeof(int*));;
    int mem_sum = mem_matrix_1 + mem_matrix_2 + mem_matrix_res;
     rows = matrix_res.rows;
     columns = matrix_res.columns;
    int matrix_1_non_zero = matrix_1->non_zero;
    int matrix_2_non_zero = matrix_2->non_zero;
    int matrix_res_non_zero = matrix_res.non_zero;

    free_sparse_matrix_t(&sparse_matrix_res);
    free_matrix_t(&matrix_res);

    printf("Сравние времени\n\n");

    printf("Время затраченное для сложения матриц в разряженном виде (микросекунды): %llu\n", res_sparse_matrix);
    printf("Время затраченное для сложения матриц в неразряженном виде (микросекунды): %llu\n", res_matrix);

    printf("Сравние памяти\n\n");

    printf("Память при сложении в разряженном виде\n");
    printf("Размеры матриц: %dx%d\n", sparse_rows, sparse_columns);
    printf("Количество ненулевых элементов в 1 матрице: %d\n", sparse_matrix_1_non_zero);
    printf("Количество ненулевых элементов в 2 матрице: %d\n", sparse_matrix_2_non_zero);
    printf("Количество ненулевых элементов в результирующей матрице: %d\n", sparse_matrix_res_non_zero);
    printf("Суммарный объем затраченной памяти (в байтах): %d\n\n", mem_sum_sparse);

    printf("Память при сложении в неразряженном виде\n");
    printf("Размеры матриц: %dx%d\n", rows, columns);
    printf("Количество ненулевых элементов в 1 матрице: %d\n", matrix_1_non_zero);
    printf("Количество ненулевых элементов в 2 матрице: %d\n", matrix_2_non_zero);
    printf("Количество ненулевых элементов в результирующей матрице: %d\n", matrix_res_non_zero);
    printf("Суммарный объем затраченной памяти (в байтах): %d\n", mem_sum);

    LOG_INFO("finish successfully");
    return err;
}
