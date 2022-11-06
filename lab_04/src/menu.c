#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/log.h"
#include "../inc/menu.h"
#include "../inc/read_words.h"
#include "../inc/read_string.h"
#include "../inc/num_pop.h"
#include "../inc/print_reversed.h"

void print_menu(void)
{
    LOG_INFO("started");
    printf("\n"
           "Пункты меню:\n"
           "1 - Добавить слова в стек на массиве\n"
           "2 - Удалить слова из стека на массиве\n"
           "3 - Вывести текущее состояние стека на массиве\n"
           "4 - Добавить слова в стек на списке\n"
           "5 - Удалить слова из стека на списке\n"
           "6 - Вывести текущее состояние стека на списке\n"
           "7 - Вывести адреса освобожденных областей\n"
           "8 - Распечатать слова в обратном порядке в перевернутом виде\n"
           "0 - выход из программы\n");
    LOG_INFO("finish successfully");
}

void print_error_message(int err)
{
    LOG_INFO("started");
    switch (err)
    {
        case ERR_FULL_STACK:
            printf("Ошибка, стек полный\n");
            break;
        case ERR_EMPTY_STACK:
            printf("Ошибка, стек пустой\n");
            break;
        case ERR_ACTION:
            printf("Ошибка выбора пункта меню\n");
            break;
        case ERR_READ_STRING:
            printf("Ошибка чтения слова\n");
            break;
        case ERR_STRING_SIZE:
            printf("Ошибка размера слова\n");
            break;
        case ERR_EMPTY_STRING:
            printf("Ошибка, пустая строка\n");
            break;
        case ERR_SPACE:
            printf("Ошибка, в слове есть пробелы\n");
            break;
        case ERR_WORDS_COUNT:
            printf("Ошибка ввода количества слов\n");
            break;
        case ERR_FULL_FREE_AREAS:
            printf("Ошибка, массив очищенных облостей полный\n");
            break;
        case ERR_EMPTY_FREE_AREAS:
            printf("Ошибка, массив очищенных облостей пустой\n");
            break;
        default:
            printf("Ошибка взаимодействия с программой\n");
            break;
    }
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

    clear_stdin();

    if (*action < 0 || *action > 8)
    {
        err = ERR_ACTION;
        LOG_ERROR(err);
        return err;
    }

    LOG_INFO("finish successfully");
    return err;
}

int do_action(int action, array_stack_t *array_stack, list_stack_t **list_stack, free_areas_t *ptrs)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    switch (action)
    {
        case 1:
        {
            err = array_read_words(array_stack);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        }
        case 2:
        {
            err = array_num_pop(array_stack);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        }
        case 3:
        {
            err = array_print(array_stack);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        }
        case 4:
        {
            err = list_read_words(list_stack, ptrs);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;
        }
        case 5:
        {
            err = list_num_pop(list_stack, ptrs);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
            }
            break;

        }
        case 6:
        {
            err = list_print(list_stack);
            if (err != EXIT_SUCCESS) {
                LOG_ERROR(err);
            }
            break;
        }
        case 7:
        {
            err = print_free_areas(ptrs);
            if (err != EXIT_SUCCESS) {
                LOG_ERROR(err);
            }
            break;
        }
        case 8:
        {
            print_popped_reversed(array_stack, list_stack);
            break;
        }
        default:
        {
            data_t data;
            while (*list_stack)
                list_pop(list_stack, &data);

            exit(EXIT_SUCCESS);
            break;
        }

    }

    LOG_INFO("finish successfully");
    return err;

}