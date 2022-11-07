#ifndef __PRINT_REVERSED_H__

#define __PRINT_REVERSED_H__

#include "list_stack.h"
#include "array_stack.h"

void print_popped_reversed(array_stack_t *array_stack, list_stack_t **list_stack);
void array_print_reversed(array_stack_t *stack);
void list_print_reversed(list_stack_t **stack);
void print_word_reversed(char *word, int len_word);

#endif // __PRINT_REVERSED_H__