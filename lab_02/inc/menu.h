#ifndef UNIVERSAL_MENU_MENU_H
#define UNIVERSAL_MENU_MENU_H

#include "stdio.h"
#include "items_list.h"

struct Menu;

typedef struct Menu* menu_t;

menu_t create_menu();

void add_command(menu_t menu, void(*func)(void), const char *description);

void add_args_command(menu_t menu, void(*func)(void *), const char *description, void *packed_args);

void execute_menu(menu_t menu);

void add_sub_menu(menu_t menu, menu_t sub_menu, const char *description);

void free_menu(menu_t menu);

#endif //UNIVERSAL_MENU_MENU_H
