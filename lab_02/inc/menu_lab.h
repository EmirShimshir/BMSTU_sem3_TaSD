#ifndef __MENU_H__

#define __MENU_H__

#include "cars.h"

#define OK_ACTION 0

#define MAX_MENU_ITEM_LEN 2

void print_error_message(const int code);

void print_menu(void);

int choose_action(short int *const action);

int do_action(const short int action, car_table_t *table);

#endif