#ifndef __READ_CARS_H__

#define __READ_CARS_H__

#include "cars.h"

#define ERR_READ -1
#define ERR_WRONG_SYMBOL -2

// ! Добавить функции read

int check_and_assign_brand(const char *const read_brand, car_table_t *table, int *const err_row);

int check_and_assign_country(const char *const read_country, car_table_t *table, int *const err_row);

int check_and_assign_color(const char *const read_color, car_table_t *table, int *const err_row);

int check_and_assign_price(const char *const read_price, car_table_t *table, int *const err_row);

int check_and_assign_condition(const char *const read_condition, car_table_t *table, int *const err_row);

int check_and_assign_warranty(const char *const read_warranty, car_table_t *table, int *const err_row);

int check_and_assign_year(const char *const read_year, car_table_t *table, int *const err_row);

int check_and_assign_mileage(const char *const read_mileage, car_table_t *table, int *const err_row);

int check_and_assign_repairs_num(const char *const read_repairs_num, car_table_t *table, int *const err_row);

int check_and_assign_owners_num(const char *const read_owners_num, car_table_t *table, int *const err_row);

int read_csv_file(FILE *const file, car_table_t *table, int *const err_row);

int upload_from_file(car_table_t *table);

int read_record(car_table_t *table);

int read_delete_price(unsigned int *const price);

int read_find_brand(char *const brand);

#endif