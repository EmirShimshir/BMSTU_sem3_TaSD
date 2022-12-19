#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>

#include "graph.h"

void welcome_print();
int get_command(int *command);
matrix_t *read_matrix(FILE *f);
void print_matrix(FILE *f, matrix_t *graph);
void to_dot(matrix_t *graph);

#endif // __IO_H__
