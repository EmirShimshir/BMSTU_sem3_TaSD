#ifndef __PRINT_H__

#define __PRINT_H__

#include "defs.h"
#include "types.h"
#include "print.h"
#include <stdio.h>

void print_msg_start();
void print_msg_read_double();
void print_msg_read_int();
void print_msg_print_double();
void print_msg_print_double();
void print_double(double_t *number);
int print_error(int err);

#endif // __PRINT_H__
