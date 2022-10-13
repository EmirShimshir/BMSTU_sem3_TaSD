#ifndef __MENU_H__

#define __MENU_H__

#include "countries.h"

int choose_action(int *const action);
int do_action(const int action, country_table_t *table);

#endif // __MENU_H__
