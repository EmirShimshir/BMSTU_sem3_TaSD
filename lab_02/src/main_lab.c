/**
 * @mainpage
 * *Вариант 11*\n\n
 * Сортировка и поиск в таблице со списком машин
 * **Автор:** Маслова Марина
 * **Группа:** ИУ7-33Б
 */

#include <stdio.h>
#include <stdbool.h>

#include "menu.h"
#include "cars.h"
#include "errors.h"

#define OK 0

int main(void)
{
    setbuf(stdout, NULL);

    puts("ПРОГРАММА ОБРАБОТКИ СПИСКА МАШИН");

    int exit_code = OK;
    car_table_t table;
    table.len = 0;

    while (true)
    {
        short int action;
        print_menu();
        exit_code = choose_action(&action);

        if (exit_code)
        {
            print_error_message(exit_code);

            if (ERR_CLOSE_FILE == exit_code)
                return ERR_CLOSE_FILE;

            continue;
            // return exit_code;
        }

        exit_code = do_action(action, &table);

        if (exit_code)
        {
            print_error_message(exit_code);
            continue;
            // return exit_code;
        }
    }

    return OK;
}