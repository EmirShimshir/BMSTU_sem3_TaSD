#ifndef __MENU_H__

#define __MENU_H__

#include "array_stack.h"
#include "list_stack.h"
#include "free_areas.h"

void print_menu(void);
void print_error_message(int err);
int choose_action(int *action);
int do_action(int action, array_stack_t *array_stack, list_stack_t **list_stack, free_areas_t *ptrs);

#endif // __MENU_H__
