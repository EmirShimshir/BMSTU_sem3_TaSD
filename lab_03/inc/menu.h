#ifndef __MENU_H__

#define __MENU_H__

#include "matrix.h"
#include "sparse_matrix.h"

void print_menu(void);
int choose_action(int *action);
int do_action(int action, sparse_matrix_t *sparse_matrix_1, sparse_matrix_t *sparse_matrix_2, matrix_t *matrix_1, matrix_t *matrix_2);

#endif // __MENU_H__