#ifndef __SORT_H__
#define __SORT_H__

#include <string.h>
#include "countries.h"
#include "print.h"

void sort_table_key(struct keys *key, size_t count);
void qsort_table_key(struct keys *key, size_t count);
void sort_table_with_key(struct flats *flat, size_t count, struct keys *key);
void sort_table(struct flats *flat, size_t count);
void qsort_table(struct flats *flat, size_t count);
void swap_sort(struct flats *flat_arr,size_t count);
int compare_square(const void *a, const void *b);

#endif // __SORT_H__
