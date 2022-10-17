#ifndef __SORT_COUNTRIES_H__
#define __SORT_COUNTRIES_H__

#include "countries.h"

void sort_table_key(country_key_t *key_arr, size_t count);
void swap_key(country_key_t *key_a, country_key_t *key_b);
void qsort_table_key(country_key_t *key_arr, size_t count);
void qsort_table(country_t *country_arr, size_t count);
int compare_key(const void *a, const void *b);
int compare(const void *a, const void *b);
void sort_table(country_t *country_arr, size_t count);
void print_sort_table_by_key(country_t *country_arr, size_t count, country_key_t *key_arr);

#endif // __SORT_COUNTRIES_H__
