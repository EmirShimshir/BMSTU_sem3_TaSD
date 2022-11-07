#include <stdbool.h>

#include "../inc/errors.h"
#include "../inc/log.h"
#include "../inc/array_stack.h"
#include "../inc/list_stack.h"
#include "../inc/menu.h"

int main(void)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    printf("Программа для работы со стеком\n"
           "Шимшир Эмирджан ИУ7-33Б В-24\n"
           "\n"
           "(по умолчанию необходимо вводить только целые числа)\n"
           "(слова необходимо вводить только на английском языке)\n"
           "\n");

    array_stack_t arr_stack = { .len = 0 };
    list_stack_t *list_stack = NULL;
    free_areas_t ptrs = { .len = 0 };

    while (true)
    {
        int action;
        print_menu();

        err = choose_action(&action);
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            print_error_message(err);
            continue;
        }

        err = do_action(action, &arr_stack, &list_stack, &ptrs);

        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            print_error_message(err);
            continue;
        }
    }

    LOG_INFO("finish successfully");
    return err;
}