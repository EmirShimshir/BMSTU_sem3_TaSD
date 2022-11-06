#ifndef __NUM_POP_H__

#define __NUM_POP_H__

#include "array_stack.h"
#include "list_stack.h"
#include "free_areas.h"

int array_num_pop(array_stack_t *array_stack);
int list_num_pop(list_stack_t **list_stack, free_areas_t *ptrs);

#endif // __NUM_POP_H__