#ifndef __PRINT_CARS_H__

#define __PRINT_CARS_H__

#include "cars.h"

void print_column_line(const int line_len);

void print_str(const char *const str, const int max_len);

void print_header(void);

void print_down_line(void);

void print_record(const car_t *const record);

void print_cars(car_table_t *table);

void print_cars_keys(car_key_table_t *table);

void print_key_down_line(void);

void print_key_header(void);

void print_key_record(const car_key_t *const record);

#endif