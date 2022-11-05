#include <stdio.h>
#include <stdlib.h>

#include "../inc/menu.h"
#include "../inc/log.h"
#include "../inc/errors.h"
#include "../inc/matrix.h"
#include "../inc/sparse_matrix.h"
#include "../inc/actions.h"

void print_error_message(int err)
{
    switch (err)
    {
        case ERR_MEM_ALLOC:
            printf("Ошибка выделения памяти\n");
            break;
        case ERR_ACTION:
            printf("Ошибка выбора пункта меню\n");
            break;
        case ERR_INPUT_ROWS:
            printf("Ошибка ввода количества строк\n");
            break;
        case ERR_INPUT_COLUMNS:
            printf("Ошибка ввода количества столбцов\n");
            break;
        case ERR_INPUT_NON_ZERO:
            printf("Ошибка ввода количества ненулевых элементов\n");
            break;
        case ERR_INPUT_ELEM:
            printf("Ошибка ввода значения элемента\n");
            break;
        case ERR_INPUT_PRINT_METHOD:
            printf("Ошибка ввода метода вывода матрицы\n");
            break;
        case ERR_MATRIX_NOT_ALLOCATED:
            printf("Ошибка, матрицы не проинициализированы\n");
            break;
        case ERR_DIFF_MATRIX_SIZE:
            printf("Ошибка, матрицы разного размера\n");
            break;
        default:
            printf("Ошибка взаимодействия с программой\n");
            break;;
    }
}

void print_menu(void)
{
    LOG_INFO("started");
    printf("\n"
           "Пункты меню:\n"
           "1 - ввести первую матрицу с клавиатуры\n"
           "2 - сгенерировать первую матрицу\n"
           "3 - вывести первую матрицу\n"
           "4 - ввести вторую матрицу с клавиатуры\n"
           "5 - сгенерировать вторую матрицу\n"
           "6 - вывести вторую матрицу\n"
           "7 - сложить матрицы в стандортном виде\n"
           "8 - сложить матрицы в разряженном виде\n"
           "9 - показать сравнение времени и памяти двух способов сложения\n"
           "0 - выход из программы\n");
    LOG_INFO("finish successfully");
}

int choose_action(int *action)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    printf("Выберете пункт меню: ");

    if (scanf("%d", action) != 1)
    {
        err = ERR_ACTION;
        LOG_ERROR(err);
        return err;
    }

    if (*action < 0 || *action > 9)
    {
        err = ERR_ACTION;
        LOG_ERROR(err);
        return err;
    }

    LOG_INFO("finish successfully");
    return err;
}

int do_action(int action, sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, matrix_t *matrix_1, matrix_t *matrix_2)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    switch (action)
    {
        case 1:
            err = read_matrix( matrix_1, sparse_matrix_1);
            if (err != EXIT_SUCCESS)
            {
                free_matrix_t(matrix_1);
                free_sparse_matrix_t(sparse_matrix_1);
                LOG_ERROR(err);
            }
            break;
        case 2:
            err = generate_matrix(matrix_1, sparse_matrix_1);
            if (err != EXIT_SUCCESS)
            {
                free_matrix_t(matrix_1);
                free_sparse_matrix_t(sparse_matrix_1);
                LOG_ERROR(err);
            }
            break;
        case 3:
            err = print_matrix(matrix_1, sparse_matrix_1);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        case 4:
            err = read_matrix( matrix_2, sparse_matrix_2);
            if (err != EXIT_SUCCESS)
            {
                free_matrix_t(matrix_2);
                free_sparse_matrix_t(sparse_matrix_2);
                LOG_ERROR(err);
            }
            break;
        case 5:
            err = generate_matrix(matrix_2, sparse_matrix_2);
            if (err != EXIT_SUCCESS)
            {
                free_matrix_t(matrix_2);
                free_sparse_matrix_t(sparse_matrix_2);
                LOG_ERROR(err);
            }
            break;
        case 6:
            err = print_matrix(matrix_2, sparse_matrix_2);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        case 7:
            err = addition_matrix_t(matrix_1, matrix_2);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        case 8:
            err = addition_sparse_matrix_t(sparse_matrix_1, sparse_matrix_2);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        case 9:
            err = compare_addition(sparse_matrix_1, sparse_matrix_2, matrix_1, matrix_2);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        default:
            free_sparse_matrix_t(sparse_matrix_1);
            free_sparse_matrix_t(sparse_matrix_2);
            free_matrix_t(matrix_1);
            free_matrix_t(matrix_2);

            exit(EXIT_SUCCESS);
            break;
    }

    LOG_INFO("finish successfully");
    return err;
}