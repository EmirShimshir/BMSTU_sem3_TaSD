#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>


#include "../inc/compare.h"
#include "../inc/sort_countries.h"
#include "../inc/countries.h"
#include "../inc/defs.h"
#include "../inc/read.h"

#define COUNT_EXPERIMENTS 1000

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}

void compare_sort(country_t *country_arr, size_t count, country_key_t *key_arr)
{
    printf("Count countries: %zu", count);

    unsigned long long beg_test_q, end_test_q, beg_key_test_q, end_key_test_q, res_test_q = 0, res_key_test_q = 0;
    country_t country_arr_test_q[MAX_TABLE];
    country_key_t key_arr_test_q[MAX_TABLE];

    for(int i = 0; i < COUNT_EXPERIMENTS; i++)
    {
        memcpy(country_arr_test_q, country_arr, sizeof(country_t) * count);
        beg_test_q = microseconds_now();
        qsort_table(country_arr_test_q, count);
        end_test_q = microseconds_now();
        res_test_q += (end_test_q - beg_test_q);
    }

    for(int i = 0; i < COUNT_EXPERIMENTS; i++)
    {
        memcpy(key_arr_test_q, key_arr, sizeof(country_key_t) * count);
        beg_key_test_q = microseconds_now();
        qsort_table_key(key_arr_test_q, count);
        end_key_test_q = microseconds_now();
        res_key_test_q += (end_key_test_q - beg_key_test_q);
    }

    printf("\n"
           "Qsort table time (microseconds):            %llu\n", res_test_q / COUNT_EXPERIMENTS);
    printf("Qsort table key time (microseconds):        %llu\n", res_key_test_q / COUNT_EXPERIMENTS);

    unsigned long long beg_test_b, end_test_b, beg_key_test_b, end_key_test_b, res_test_b = 0, res_key_test_b = 0;
    country_t country_arr_test_b[MAX_TABLE];
    country_key_t key_arr_test_b[MAX_TABLE];

    for(int i = 0; i < COUNT_EXPERIMENTS; i++)
    {
        memcpy(country_arr_test_b, country_arr, sizeof(country_t) * count);
        beg_test_b = microseconds_now();
        sort_table(country_arr_test_b, count);
        end_test_b = microseconds_now();
        res_test_b += (end_test_b - beg_test_b);
    }

    for(int i = 0; i < COUNT_EXPERIMENTS; i++)
    {
        memcpy(key_arr_test_b, key_arr, sizeof(country_key_t) * count);
        beg_key_test_b = microseconds_now();
        sort_table_key(key_arr_test_b, count);
        end_key_test_b = microseconds_now();
        res_key_test_b += (end_key_test_b - beg_key_test_b);
    }

    printf("\n"
           "Bubble sort table time (microseconds):      %llu\n", res_test_b / COUNT_EXPERIMENTS);
    printf("Bubble sort key table time (microseconds):  %llu\n", res_key_test_b / COUNT_EXPERIMENTS);

    size_t size_table = sizeof(country_t) * count;
    size_t size_key = sizeof(country_key_t) * count;
    printf("\n"
           "Size of memory table (byte):                %zu\n", size_table);
    printf("Size of memory table with key (byte):       %zu\n", size_table + size_key);

}
