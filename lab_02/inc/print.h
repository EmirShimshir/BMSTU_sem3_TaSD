#ifndef __PRINT_H__
#define __PRINT_H__

#include <stdlib.h>

#include "countries.h"

#define NORMALT "\033[0m"
#define REDT "\033[35m"
#define GREENT "\033[32m"
#define BLUET "\033[34m"

//void print_table_rama(void);
void print_table(country_t *country, size_t count);
void print_country(country_t country, size_t count);
void print_info(void);
void print_menu(void);


#endif // __PRINT_H__
