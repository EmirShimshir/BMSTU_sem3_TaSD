#include <string.h>
#include "../inc/sort_countries.h"
#include "../inc/countries.h"
#include "../inc/add_del_country.h"
#include "../inc/print.h"

void swap_key(country_key_t *key_a, country_key_t *key_b)
{
    country_key_t temp_key;
    memcpy(&temp_key, key_a, sizeof(country_key_t));
    memcpy(key_a, key_b, sizeof(country_key_t));
    memcpy(key_b, &temp_key, sizeof(country_key_t));
}

void sort_table_key(country_key_t *key_arr, size_t count)
{
    for (size_t i = 0; i < count; i++)
        for(size_t j = 0;  j < count - 1; j++)
            if((key_arr + j)->count_people  > (key_arr + j + 1)->count_people)
                swap_key(key_arr + j, key_arr + j + 1);
}

int compare_key(const void *a, const void *b)
{
    return (((country_key_t *)a)->count_people - ((country_key_t *)b)->count_people);
}

int compare(const void *a, const void *b)
{
    return (((country_t *)a)->count_people - ((country_t *)b)->count_people);
}

void qsort_table_key(country_key_t *key_arr, size_t count)
{
    qsort(key_arr, count, sizeof(country_key_t), compare_key);
}

void qsort_table(country_t *country_arr, size_t count)
{
    qsort(country_arr, count, sizeof(country_t), compare);
}

void sort_table(country_t *country_arr, size_t count)
{
    for (size_t i = 0; i < count; i++)
        for(size_t j = 0;  j < count - 1; j++)
            if((country_arr + j)->count_people  > (country_arr + j + 1)->count_people)
                swap(country_arr + j, country_arr + j + 1);
}

void print_sort_table_by_key(country_t *country_arr, size_t count, country_key_t *key_arr)
{
    print_table_head();
    for(size_t i = 0; i < count ; i++)
        print_country(*(country_arr + ((key_arr + i)->index - 1)), i + 1);
}
