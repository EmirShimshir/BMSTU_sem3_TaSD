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
int read_order(int *order);
int read_int_str(char *read_str, int max_int_len);
void normalize_number(double_t *number);
int read_int(int_t *number);

#endif // __READ_H__
