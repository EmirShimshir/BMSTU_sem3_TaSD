#ifndef __ADD_DEL_COUNTRY_H__
#define __ADD_DEL_COUNTRY_H__

#include <stdlib.h>

#include "countries.h"

int add_country(country_t *country_arr, country_key_t *key_arr, size_t *count);
int trim(char *s);
void del_country(country_t *country_arr, size_t *count, int count_people);
void move(country_t *country_arr, size_t *count, size_t i);
void swap(country_t *country_a, country_t *country_b);

#endif // __ADD_DEL_COUNTRY_H__
