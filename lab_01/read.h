#ifndef __READ_H__

#define __READ_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "defs.h"
#include "types.h"
#include "print.h"

int read_double(double_t *num);
int read_mantissa(double_t *number);
int read_order(int *const order);
int read_int_str(char *const read_str, const int max_int_len);
void normalize_number(double_t *const number);
int read_int(int_t *const number);

#endif // __READ_H__
