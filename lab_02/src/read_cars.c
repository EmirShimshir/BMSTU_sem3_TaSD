#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "cars.h"
#include "read_cars.h"
#include "errors.h"
#include "my_string.h"

int check_and_assign_brand(const char *const read_brand, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_brand) > MAX_BRAND_LEN / 2)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_BRAND;
    }
    else
        strcpy((char *) &table->table[table->len - 1].brand, read_brand);
    
    return CARS_OK;
}

int check_and_assign_country(const char *const read_country, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_country) > MAX_COUNTRY_LEN / 2)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_COUNTRY;
    }
    else
        strcpy((char *) &table->table[table->len - 1].country, read_country);

    return CARS_OK;
}

int check_and_assign_color(const char *const read_color, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_color) > MAX_COLOR_LEN / 2)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_COLOR;
    }
    else
        strcpy((char *) &table->table[table->len - 1].color, read_color);

    return CARS_OK;
}

int check_and_assign_price(const char *const read_price, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_price) > MAX_PRICE_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_PRICE;
    }
    else
    {
        char *end_prt;
        long int price = strtol(read_price, &end_prt, 10);

        if (*end_prt != '\0')
        {
            *err_row = table->len;
            return ERR_READ_PRICE;
        }
        else if (price < 0 || price > UINT_MAX)
        {
            *err_row = table->len;
            return ERR_WRONG_PRICE;
        }
        else
            table->table[table->len - 1].price = (unsigned int) price;
    }

    return CARS_OK;
}

int check_and_assign_condition(const char *const read_condition, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_condition) > MAX_CONDITION_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_CONDITION;
    }
    else if (!strcmp(read_condition, "new"))
        table->table[table->len - 1].condition = NEW;

    else if (!strcmp(read_condition, "used"))
        table->table[table->len - 1].condition = USED;

    else
    {
        *err_row = table->len;
        return ERR_WRONG_CONDITION;
    }

    return CARS_OK;
}

int check_and_assign_warranty(const char *const read_warranty, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_warranty) > MAX_WARRANTY_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_WARRANTY;
    }
    else if (USED == table->table[table->len - 1].condition && strcmp(read_warranty, "-"))
    {
        *err_row = table->len;
        return ERR_USED_WARRANTY;
    }
    else if (USED != table->table[table->len - 1].condition)
    {
        char *end_prt;
        long int warranty = strtol(read_warranty, &end_prt, 10);

        if (*end_prt != '\0')
        {
            *err_row = table->len;
            return ERR_READ_WARRANTY;
        }
        else if (warranty < 0 || warranty > USHRT_MAX)
        {
            *err_row = table->len;
            return ERR_WRONG_WARRANTY;
        }
        else
            table->table[table->len - 1].more_info.new_car.warranty = (unsigned short int) warranty;
    }

    return CARS_OK;
}

int check_and_assign_year(const char *const read_year, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_year) > MAX_YEAR_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_YEAR;
    }
    else if (NEW == table->table[table->len - 1].condition && strcmp(read_year, "-"))
    {
        *err_row = table->len;
        return ERR_NEW_YEAR;
    }
    else if (NEW != table->table[table->len - 1].condition)
    {
        char *end_prt;
        long int year = strtol(read_year, &end_prt, 10);

        if (*end_prt != '\0')
        {
            *err_row = table->len;
            return ERR_READ_YEAR;
        }
        else if (year < 0 || year > USHRT_MAX)
        {
            *err_row = table->len;
            return ERR_WRONG_YEAR;
        }
        else
            table->table[table->len - 1].more_info.used_car.year = (unsigned short int) year;
    }

    return CARS_OK;
}

int check_and_assign_mileage(const char *const read_mileage, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_mileage) > MAX_MILEAGE_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_MILEAGE;
    }
    else if (NEW == table->table[table->len - 1].condition && strcmp(read_mileage, "-"))
    {
        *err_row = table->len;
        return ERR_NEW_MILEAGE;
    }
    else if (NEW != table->table[table->len - 1].condition)
    {
        char *end_prt;
        long int mileage = strtol(read_mileage, &end_prt, 10);

        if (*end_prt != '\0')
        {
            *err_row = table->len;
            return ERR_READ_MILEAGE;
        }
        else if (mileage < 0 || mileage > UINT_MAX)
        {
            *err_row = table->len;
            return ERR_WRONG_MILEAGE;
        }
        else
            table->table[table->len - 1].more_info.used_car.mileage = (unsigned int) mileage;
    }
    
    return CARS_OK;
}

int check_and_assign_repairs_num(const char *const read_repairs_num, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_repairs_num) > MAX_REPAIRS_NUM_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_REPAIRS_NUM;
    }
    else if (NEW == table->table[table->len - 1].condition && strcmp(read_repairs_num, "-"))
    {
        *err_row = table->len;
        return ERR_NEW_REPAIRS_NUM;
    }
    else if (NEW != table->table[table->len - 1].condition)
    {
        char *end_prt;
        long int repairs_num = strtol(read_repairs_num, &end_prt, 10);

        if (*end_prt != '\0')
        {
            *err_row = table->len;
            return ERR_READ_REPAIRS_NUM;
        }
        else if (repairs_num < 0 || repairs_num > USHRT_MAX)
        {
            *err_row = table->len;
            return ERR_WRONG_REPAIRS_NUM;
        }
        else
            table->table[table->len - 1].more_info.used_car.repairs_num =
                 (unsigned short int) repairs_num;
    }

    return CARS_OK;
}

int check_and_assign_owners_num(const char *const read_owners_num, car_table_t *table, int *const err_row)
{
    if (my_strlen(read_owners_num) > MAX_OWNERS_NUM_LEN)
    {
        *err_row = table->len;
        return ERR_TOO_LONG_OWNERS_NUM;
    }
    else if (NEW == table->table[table->len - 1].condition && strcmp(read_owners_num, "-"))
    {
        *err_row = table->len;
        return ERR_NEW_OWNERS_NUM;
    }
    else if (NEW != table->table[table->len - 1].condition)
    {
        char *end_prt;
        long int owners_num = strtol(read_owners_num, &end_prt, 10);

        if (*end_prt != '\0')
        {
            *err_row = table->len;
            return ERR_READ_OWNERS_NUM;
        }
        else if (owners_num < 0 || owners_num > USHRT_MAX)
        {
            *err_row = table->len;
            return ERR_WRONG_OWNERS_NUM;
        }
        else
            table->table[table->len - 1].more_info.used_car.owners_num =
                (unsigned short int) owners_num;
    }
     return CARS_OK;
}

int read_csv_file(FILE *const file, car_table_t *table, int *const err_row)
{
    char str[MAX_TABLE_STR_LEN + 2];
    table->len = -1;
    int exit_code = CARS_OK;
    *err_row = 0;

    while (fgets(str, MAX_TABLE_STR_LEN + 3, file))
    {
        table->len++;

        if (table->len > MAX_TABLE_LEN)
            return ERR_TOO_BIG_FILE;

        size_t len = table->len;
        *err_row = table->len + 1;

        if (0 == len)
            continue;

        if (my_strlen(str) > MAX_TABLE_STR_LEN + 2)
            return ERR_TOO_LONG_STR;

        char *field_prt = strtok(str, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_brand(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_country(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_color(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_price(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_condition(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_warranty(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_year(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_mileage(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_repairs_num(field_prt, table, err_row);

        if (exit_code)
            return exit_code;

        field_prt = strtok(NULL, ",\n");

        if (!field_prt)
            return ERR_INCORRECT_FILE;

        exit_code = check_and_assign_owners_num(field_prt, table, err_row);

        if (exit_code)
            return exit_code;
    }

    if (table->len == 0)
        return ERR_INCORRECT_FILE;

    return exit_code;
}

int upload_from_file(car_table_t *table)
{
    table->len = 0;
    int exit_code = CARS_OK;
    char *file_name = NULL;
    size_t len = 0;
    int read;

    puts("\nФайл с данными в формате csv, где в первой строке расположен заголовок таблицы,");
    puts("а в последующих по одной записи с полями, разделенными запятой \",\"\n");
    puts("Введите имя файла (с путем при нахождении файла в другой директории):");

    if ((read = getline(&file_name, &len, stdin)) != -1)
    {
        if ('\n' == file_name[read - 1])
            file_name[read - 1] = '\0';

        FILE *file = fopen(file_name, "r");
        free(file_name);
        
        if (file)
        {
            fseek(file, 0, SEEK_END);
            long pos = ftell(file);

            if (pos <= 0)
                return ERR_EMPTY_FILE;

            rewind(file);

            int err_row;
            exit_code = read_csv_file(file, table, &err_row);

            if (fclose(file) == EOF)
                return ERR_CLOSE_FILE;

            if (exit_code)
            {
                printf("\nОшибка чтения файла в %d-й строке.", err_row);
                return exit_code;
            }
        }
        else
            return ERR_OPEN_FILE;
    }
    else
        return ERR_READ_FILE_NAME;
}

int read_brand(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_BRAND_LEN + 2];

    if (read_str(str, MAX_BRAND_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_brand(str, table, &err_row);

    return exit_code;
}

int read_find_brand(char *const brand)
{
    int exit_code = CARS_OK;
    char str[MAX_BRAND_LEN + 2];

    if (read_str(str, MAX_BRAND_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    if (my_strlen(str) > MAX_BRAND_LEN)
        return ERR_TOO_LONG_BRAND;

    else
        strcpy(brand, str);
    
    return CARS_OK;
}

int read_country(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_COUNTRY_LEN + 2];

    if (read_str(str, MAX_COUNTRY_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_country(str, table, &err_row);

    return exit_code;
}

int read_color(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_COLOR_LEN + 2];

    if (read_str(str, MAX_COLOR_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_color(str, table, &err_row);

    return exit_code;
}

int read_price(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_PRICE_LEN + 2];

    if (read_str(str, MAX_PRICE_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_price(str, table, &err_row);

    return exit_code;
}

int read_delete_price(unsigned int *const price)
{
    char str[MAX_PRICE_LEN + 2];

    if (read_str(str, MAX_PRICE_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;
    
    if (my_strlen(str) > MAX_PRICE_LEN)
        return ERR_TOO_LONG_PRICE;

    else
    {
        char *end_prt;
        long int l_price = strtol(str, &end_prt, 10);

        if (*end_prt != '\0')
            return ERR_READ_PRICE;

        else if (l_price < 0 || l_price > UINT_MAX)
            return ERR_WRONG_PRICE;

        else
            *price = (unsigned int) l_price;
    }

    return CARS_OK;
}

int read_condition(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[3];

    if (read_str(str, 4, stdin))
        return ERR_WRONG_CONDITION;

    if (my_strlen(str) != 1)
        return ERR_WRONG_CONDITION;

    char ch = str[0];
    int err_row;

    if (ch == 'N' || ch == 'n')
        exit_code = check_and_assign_condition("new", table, &err_row);

    else if (ch == 'U' || ch == 'u')
        exit_code = check_and_assign_condition("used", table, &err_row);

    else
        exit_code = ERR_WRONG_CONDITION;

    return exit_code;
}

int read_warranty(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_WARRANTY_LEN + 2];

    if (read_str(str, MAX_WARRANTY_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_warranty(str, table, &err_row);

    return exit_code;
}

int read_year(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_YEAR_LEN + 2];

    if (read_str(str, MAX_YEAR_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_year(str, table, &err_row);

    return exit_code;
}

int read_mileage(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_MILEAGE_LEN + 2];

    if (read_str(str, MAX_MILEAGE_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_mileage(str, table, &err_row);

    return exit_code;
}

int read_repairs_num(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_REPAIRS_NUM_LEN + 2];

    if (read_str(str, MAX_REPAIRS_NUM_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_repairs_num(str, table, &err_row);

    return exit_code;
}

int read_owners_num(car_table_t *table)
{
    int exit_code = CARS_OK;
    char str[MAX_OWNERS_NUM_LEN + 2];

    if (read_str(str, MAX_OWNERS_NUM_LEN + 3, stdin))
        return ERR_READ;

    int err_row;

    if (!my_strlen(str))
        return ERR_READ;

    exit_code = check_and_assign_owners_num(str, table, &err_row);

    return exit_code;
}

int read_record(car_table_t *table)
{
    if (table->len >= MAX_TABLE_LEN)
    {
        puts("Достигнут максимальный размер таблицы.");
        puts("Удалите данные для возможности добавления записи!");
    }
    else
    {
        puts("\nВведите данные о новом автомобиле.\n");
        int exit_code = CARS_OK;
        table->len++;

        printf("Марка (max_len = 15): ");

        exit_code = read_brand(table);

        if (exit_code)
        {
            table->len--;
            return exit_code;
        }

        printf("Cтрана-произоводитель (max_len = 20): ");

        exit_code = read_country(table);

        if (exit_code)
        {
            table->len--;
            return exit_code;
        }

        printf("Цвет (max_len = 15): ");

        exit_code = read_color(table);

        if (exit_code)
        {
            table->len--;
            return exit_code;
        }

        printf("Цена (тыс руб): ");

        exit_code = read_price(table);

        if (exit_code)
        {
            table->len--;
            return exit_code;
        }

        printf("Состояние (N - новый, U - б/у): ");

        exit_code = read_condition(table);

        if (exit_code)
        {
            table->len--;
            return exit_code;
        }

        if (NEW == table->table[table->len - 1].condition)
        {
            printf("Гарантия (лет): ");

            exit_code = read_warranty(table);

            if (exit_code)
            {
                table->len--;
                return exit_code;
            }
        }
        else
        {
            printf("Год выпуска: ");

            exit_code = read_year(table);

            if (exit_code)
            {
                table->len--;
                return exit_code;
            }

            printf("Пробег: ");

            exit_code = read_mileage(table);

            if (exit_code)
            {
                table->len--;
                return exit_code;
            }
            
            printf("Количество ремонтов: ");

            exit_code = read_repairs_num(table);

            if (exit_code)
            {
                table->len--;
                return exit_code;
            }

            printf("Количество собственников: ");

            exit_code = read_owners_num(table);

            if (exit_code)
            {
                table->len--;
                return exit_code;
            }

        }
        puts("Данные об автомобиле успешно добавлены");
    }

    return CARS_OK;
}
