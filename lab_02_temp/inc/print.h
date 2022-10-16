#ifndef __PRINT_H__
#define __PRINT_H__

#include "countries.h"

#include "stdlib.h"
#include "stdio.h"

void print_table_rama();
//void print_table_key(country_key_t *key_arr, size_t count);
void print_table(country_t *country, size_t count);
void print_country(country_t country, size_t count);

void print_info(void);
void print(void);
//void print_rules_add(void);
//void print_rules_del(void);

#endif // __PRINT_H__
