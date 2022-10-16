#ifndef __PRINT_H__
#define __PRINT_H__

#include <stdlib.h>

#include "countries.h"

void print_table_head(void);
void print_line(void);
void print_table(country_t *country, size_t count);
void print_country(country_t country, size_t count);
void print_info(void);
void print_menu(void);
void print_rules_add(void);


#endif // __PRINT_H__
