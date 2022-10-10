#include <stdio.h>
#include <stdbool.h>

#include <stdio.h>
#include "errors.h"
#include "menu.h"
#include "cars.h"
#include "my_string.h"
#include "read_cars.h"
#include "print_cars.h"
#include "errors.h"
#include "menu_lab.h"

void button_01(void *data)
{
    UNPACK_ARGS(button_01, data);

    int exit_code = OK_ACTION;

    exit_code = upload_from_file(args->table);

    if (!exit_code)
        puts("\nДанные успешно загружены!");

    print_error_message(exit_code);
}

void button_02(void *data)
{
    UNPACK_ARGS(button_02, data);

    print_cars(args->table);
}

void button_03(void *data)
{
    UNPACK_ARGS(button_03, data);

    int exit_code = OK_ACTION;

    exit_code = read_record(args->table);

    print_error_message(exit_code);
}

void button_04(void *data)
{
    UNPACK_ARGS(button_04, data);

    int exit_code = OK_ACTION;

    if (args->table->len)
    {
        exit_code = delete_record(args->table);
        print_error_message(exit_code);
    }
    else
    {
        puts("\nВ таблице нет данных!");
    }
}

void button_05(void *data)
{
    UNPACK_ARGS(button_05, data);

    create_sort_keys_table(args->table, args->keys);
    print_cars_keys(args->keys);
}

void button_06(void *data)
{
    UNPACK_ARGS(button_06, data);

    *(args->sorted_table) = *(args->table);
    heapsort(&(args->sorted_table->table), args->sorted_table->len, sizeof(car_t), &compare_records);
    print_cars(&(args->sorted_table));
}

void button_07(void *data)
{
    UNPACK_ARGS(button_07, data);

    create_sort_keys_table(args->table, args->keys);
    print_cars_by_keys(args->table, args->keys);
}

void button_08(void *data)
{
    UNPACK_ARGS(button_08, data);

    if (args->table->len)
    {
        create_keys_table(args->table, args->keys);
        compare_heapsorts(args->table, args->keys);
    }
    else
    {
        puts("\nВ таблице нет данных!");
        puts("Для оценки эффективности добавьте данные!");
    }
}

void button_09(void *data)
{
    UNPACK_ARGS(button_09, data);

    if (table->len)
    {
        create_keys_table(args->table, args->keys);
        compare_sorts_types(args->table, args->keys);
    }
    else
    {
        puts("\nВ таблице нет данных!");
        puts("Для оценки эффективности добавьте данные!");
    }
}

void button_10(void *data)
{
    UNPACK_ARGS(button_10, data);

    int exit_code = OK_ACTION;

    exit_code = find_records(table);

    print_error_message(exit_code);
}

int main()
{
    car_key_table_t keys;
    car_table_t sorted_table;
    car_table_t table;
    table.len = 0;

    menu_t menu = create_menu();

    add_args_command(menu, button_01, button_01_pack(&table));
    add_args_command(menu, button_02, "Просмотреть таблицу", button_02_pack(&table));
    add_args_command(menu, button_03, "Добавить информацию о новой машине в конец таблицы", button_03_pack(&table));
    add_args_command(menu, button_04, "Удалить машины из списка по цене", button_04_pack(&table));
    add_args_command(menu, button_05, "Просмотреть отсортированную по цене таблицу ключей", button_05_pack(&table, &keys));
    add_args_command(menu, button_06, "Вывести упорядоченную по цене таблицу", button_01_pack(&table, &sorted_table));
    add_args_command(menu, button_07, "Вывести таблицу в упорядоченном по цене виде по упорядоченной таблице ключей", button_01_pack(&table, &keys));
    add_args_command(menu, button_08, "Сравнить эффективность работы программы способами 6 и 7", button_01_pack(&table, &keys));
    add_args_command(menu, button_09, "Сравнить время работы сортировок (пирамидальной и вставками)", button_01_pack(&table), &keys);
    add_args_command(menu, button_10, "Вывести цены не новых машин указанной марки с одним предыдущим собственником, отстутсвием ремонта в указанном диапазоне цен", button_01_pack(&table, &keys));

    execute_menu(menu);

    free_menu(menu);

    return 0;
}