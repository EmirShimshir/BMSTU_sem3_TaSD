#ifndef __READ_WORDS_H__

#define __READ_WORDS_H__

#include "array_stack.h"
#include "list_stack.h"
#include "free_areas.h"

int array_read_words(array_stack_t *array_stack);
int list_read_words(list_stack_t **list_stack, free_areas_t *ptrs);

#endif // __READ_WORDS_H__