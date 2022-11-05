#include "../inc/matrix.h"
#include "../inc/sparse_matrix.h"
#include "../inc/log.h"
#include "../inc/errors.h"
#include "../inc/menu.h"

#include <stdio.h>

int main(void)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;
    int action = 0;

    printf("Программа для сложения разряженных матриц\n"
           "Шимшир Эмирджан ИУ7-33Б В-24\n"
           "\n"
           "(Пользователь должен вводить только целые числа)\n"
           "\n");

    sparse_matrix_t sparse_matrix_1 = { .A = NULL, .JA = NULL, .IA = NULL, .rows = 0, .columns = 0, .non_zero = 0};
    sparse_matrix_t sparse_matrix_2 = { .A = NULL, .JA = NULL, .IA = NULL, .rows = 0, .columns = 0, .non_zero = 0};

    matrix_t matrix_1 = { .matrix = NULL, .rows = 0, .columns = 0, .non_zero = 0};
    matrix_t matrix_2 = { .matrix = NULL, .rows = 0, .columns = 0, .non_zero = 0};

    while (1)
    {
        print_menu();
        err = choose_action(&action);
        if (err != EXIT_SUCCESS)
        {
            print_error_message(err);
            continue;
        }

        err = do_action(action, &sparse_matrix_1, &sparse_matrix_2, &matrix_1, &matrix_2);
        if (err != EXIT_SUCCESS)
        {
            print_error_message(err);
            continue;
        }
    }

    LOG_INFO("finish successfully");
    return err;
}