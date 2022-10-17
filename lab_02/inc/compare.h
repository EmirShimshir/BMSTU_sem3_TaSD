#ifndef __COMPARE_H__
#define __COMPARE_H__

#include <stdlib.h>

#include "countries.h"

unsigned long long microseconds_now(void);
void compare_sort(country_t *country_arr, size_t count, country_key_t *key_arr);

#endif // __COMPARE_H__