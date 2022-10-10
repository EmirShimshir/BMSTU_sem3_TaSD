#ifndef __CARS_H__

#define __CARS_H__

#include <stdio.h>

#define MAX_BRAND_LEN 30
#define MAX_COUNTRY_LEN 40
#define MAX_COLOR_LEN 30
#define MAX_PRICE_LEN 10
#define MAX_CONDITION_LEN 4
#define MAX_WARRANTY_LEN 3
#define MAX_YEAR_LEN 4
#define MAX_MILEAGE_LEN 7
#define MAX_REPAIRS_NUM_LEN 3
#define MAX_OWNERS_NUM_LEN 3
#define MAX_TABLE_LEN 500
#define MAX_TABLE_STR_LEN 105

typedef enum condition
{
    NEW,
    USED
} condition_t;

typedef struct
{
    short unsigned int warranty;
} new_car_t;

typedef struct
{
    short unsigned int year;
    unsigned int mileage;
    short unsigned int repairs_num;
    short unsigned int owners_num;
} used_car_t;


typedef union
{
    new_car_t new_car;
    used_car_t used_car;
} info_t;

typedef struct
{
    char brand[MAX_BRAND_LEN + 1];
    char country[MAX_COUNTRY_LEN + 1];
    char color[MAX_COLOR_LEN + 1];
    unsigned int price;
    condition_t condition;
    info_t more_info;
} car_t;

typedef struct
{
    car_t table[MAX_TABLE_LEN];
    size_t len;
} car_table_t;

typedef struct
{
    size_t num;
    unsigned int price;
} car_key_t;

typedef struct
{
    car_key_t table[MAX_TABLE_LEN];
    size_t len;
} car_key_table_t;

int delete_record(car_table_t *table);

int find_records(car_table_t *table);

void swap(void *first, void *second, size_t size);

int compare_records(const void *first, const void *second);

int compare_keys_records(const void *first, const void *second);

void heapify(void *first, size_t number, size_t bottom, size_t size,
             int (* comparator) (const void *, const void *));

void build_heap(void *first, size_t number, size_t size, int (*comparator) (const void *, const void *));

void myheapsort(void *first, size_t number, size_t size, int (*comparator) (const void *, const void *));

void create_sort_keys_table(car_table_t *table, car_key_table_t *keys);

void create_keys_table(car_table_t *table, car_key_table_t *keys);

void print_cars_by_keys(car_table_t *table, car_key_table_t *keys);

void insertionsort(void *first, size_t number, size_t size, int (*comparator) (const void *, const void *));

void compare_heapsorts(car_table_t *table, car_key_table_t *keys);

void compare_sorts_types(car_table_t *table, car_key_table_t *keys);

#endif