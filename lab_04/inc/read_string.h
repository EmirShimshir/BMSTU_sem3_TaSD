#ifndef __READ_STRING_H__

#define __READ_STRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void remove_new_line(char *target);
bool is_any_space(char *target);
int read_string(FILE *f, char *target, size_t max_target_len);
void clear_stdin(void);

#endif // __READ_STRING_H__