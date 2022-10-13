#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "cars.h"
#include "my_string.h"
#include "read_cars.h"
#include "print_cars.h"
#include "errors.h"

void print_error_message(const int code)
{
    if (ERR_WRONG_ACTION == code)
    {
        puts("\nВведенный код не соответствует ни одному действию.");
        puts("Попробуйте ещё раз.\n");
    }
    else if (ERR_READ_ACTION == code)
    {
        puts("\nНекорректный ввод кода действия.");
        puts("Попробуйте ещё раз.\n");
    }
    else if (ERR_CLOSE_FILE == code)
        puts("\nОшибка при закрытии файла!");

    else if (ERR_OPEN_FILE == code)
        puts("\nОшибка при открытии файла!");

    else if (ERR_READ_FILE_NAME == code)
        puts("\nНекорректное имя файла!");

    else if (ERR_TOO_LONG_STR == code)
        puts("\nСлишком длинная строка записи!");

    else if (ERR_TOO_LONG_BRAND == code)
        puts("\nСлишком длинная строка марки!");

    else if (ERR_TOO_LONG_COUNTRY == code)
        puts("\nСлишком длинная строка страны!");

    else if (ERR_TOO_LONG_COLOR == code)
        puts("\nСлишком длинная строка цвета!");

    else if (ERR_TOO_LONG_PRICE == code)
        puts("\nСлишком длинная строка цены!");

    else if (ERR_TOO_LONG_CONDITION == code)
        puts("\nНекорректный пункт состояния автомобиля!");

    else if (ERR_TOO_LONG_WARRANTY == code)
        puts("\nСлишком длинная строка гарантии!");

    else if (ERR_TOO_LONG_YEAR == code)
        puts("\nСлишком длинная строка года!");

    else if (ERR_TOO_LONG_MILEAGE == code)
        puts("\nСлишком длинная строка пробега!");

    else if (ERR_TOO_LONG_REPAIRS_NUM == code)
        puts("\nСлишком длинная строка количества ремонтов!");

    else if (ERR_TOO_LONG_OWNERS_NUM == code)
        puts("\nСлишком длинная строка количества собственников!");

    else if (ERR_READ_PRICE == code)
        puts("\nЦена -- целое число!");

    else if (ERR_WRONG_PRICE == code)
        puts("\nВведенная цена выходит за допустимый диапазон значений!");

    else if (ERR_WRONG_CONDITION == code)
        puts("\nСостояние задано некорректно (в файле только new или used, в строке -- n/N или u/U)!");

    else if (ERR_USED_WARRANTY == code)
        puts("\nУ б/у автомобилей не должно быть гарантии!");

    else if (ERR_READ_WARRANTY == code)
        puts("\nГарантия -- целое число!");

    else if (ERR_WRONG_WARRANTY == code)
        puts("\nВведенная гарантия выходит за доспустимый диапазон значений!");

    else if (ERR_NEW_YEAR == code)
        puts("\nУ нового автомобиля не должно быть года выпуска!");

    else if (ERR_READ_YEAR == code)
        puts("\nГод -- целое число!");

    else if (ERR_WRONG_YEAR == code)
        puts("\nЗначение года выходит за допустимый диапазон значений!");

    else if (ERR_NEW_MILEAGE == code)
        puts("\nУ нового автомобиля не должно быть пробега!");

    else if (ERR_READ_MILEAGE == code)
        puts("\nПробег -- целое число!");

    else if (ERR_WRONG_MILEAGE == code)
        puts("\nЗначение пробега выходит за допустимый диапазон значений!");

    else if (ERR_NEW_OWNERS_NUM == code)
        puts("\nУ нового автомобиля не должно быть собственников!");

    else if (ERR_READ_OWNERS_NUM == code)
        puts("\nКоличество собственников -- целое число!");

    else if (ERR_WRONG_OWNERS_NUM == code)
        puts("\nЗначение количества собственников выходит за допустимый диапазон значений!");

    else if (ERR_NEW_REPAIRS_NUM == code)
        puts("\nУ нового автомобиля не должно быть ремонта!");

    else if (ERR_READ_REPAIRS_NUM == code)
        puts("\nКоличество ремонтов -- целое число!");

    else if (ERR_WRONG_REPAIRS_NUM == code)
        puts("\nЗначение количества ремонтов выходи за допустимый диапазон значений");

    else if (ERR_NO_CARS == code)
        puts("\nМашин с такой ценой нет!");

    else if (ERR_INCORRECT_PRICES == code)
        puts("\nЦена \"от\" должна быть ниже цены \"до\"!");

    else if (ERR_NO_RECORDS == code)
        puts("\nПо заданному запросу ничего не найдено!");

    else if (ERR_EMPTY_FILE == code)
        puts("\nПустой файл!");

    else if (ERR_INCORRECT_FILE == code)
        puts("\nНеверный формат данных в файле!");

    else if (ERR_TOO_BIG_FILE == code)
        puts("\nСлишком большой файл!");
}

void print_menu(void)
{
    printf("\n"
    "     МЕНЮ\n"
    "\n"
    "1  - Загрузить таблицу машин из файла\n"
    "2  - Просмотреть таблицу\n"
    "3  - Добавить информацию о новой стране в конец таблицы\n"
    "4  - Удалить страны из списка по количеству жителей\n"
    "5  - Просмотреть отсортированную по количеству жителей таблицу ключей\n"
    "6  - Вывести упорядоченную по количеству жителей таблицу\n"
    "7  - Вывести таблицу в упорядоченном по количеству жителей виде по упорядоченной таблице ключей\n"
    "8  - Сравнить эффективность работы программы способами 6 и 7\n"
    "9  - Сравнить время работы сортировок (пирамидальной и вставками)\n"
    "10 - Вывести список стран на выбранном материке, где можно заняться указанным видом спорта\n"
    "0  - Выход\n"
    "\n")
}

int choose_action(int *const action);
{
    printf("Выберете пункт меню: \n");

    char str[MAX_MENU_ITEM_LEN + 2];
    if (read_str(str, MAX_MENU_ITEM_LEN + 3, stdin))
        return ERR_READ_ACTION;

    char *end_prt;
    long int long_str = strtol(str, &end_prt, 10);

    if (*end_prt != '\0')
        return ERR_WRONG_ACTION;

    if (long_str < 0 || long_str > 10)
        return ERR_WRONG_ACTION;

    *action = (short int) long_str;

    return READ_OK;
}

int do_action(const int action, country_table_t *table)
{
    int exit_code = OK_ACTION;
    car_key_table_t keys;
    car_table_t sorted_table;

    switch (action)
    {
        case 1:
            exit_code = upload_from_file(table);

            if (!exit_code)
                puts("\nДанные успешно загружены!");

            break;

        case 2:
            print_cars(table);
            break;

        case 3:
            exit_code = read_record(table);
            break;

        case 4:
            if (table->len)
                exit_code = delete_record(table);

            else
                puts("\nВ таблице нет данных!");

            break;

        case 5:
            create_sort_keys_table(table, &keys);
            print_cars_keys(&keys);
            break;

        case 6:
            sorted_table = *table;
            heapsort(&sorted_table.table, sorted_table.len, sizeof(car_t), &compare_records);
            print_cars(&sorted_table);
            break;

        case 7:
            create_sort_keys_table(table, &keys);
            print_cars_by_keys(table, &keys);
            break;

        case 8:
            if (table->len)
            {
                create_keys_table(table, &keys);
                compare_heapsorts(table, &keys);
            }
            else
            {
                puts("\nВ таблице нет данных!");
                puts("Для оценки эффективности добавьте данные!");
            }

            break;

        case 9:
            if (table->len)
            {
                create_keys_table(table, &keys);
                compare_sorts_types(table, &keys);
            }
            else
            {
                puts("\nВ таблице нет данных!");
                puts("Для оценки эффективности добавьте данные!");
            }

            break;

        case 10:
            exit_code = find_records(table);
            break;

        default:
            puts("\nСпасибо за использование программы!");
            puts("Автор:  МАСЛОВА МАРИНА");
            puts("Группа: ИУ7-33Б");
            exit(EXIT_SUCCESS);
            break;
    }

    return exit_code;
}