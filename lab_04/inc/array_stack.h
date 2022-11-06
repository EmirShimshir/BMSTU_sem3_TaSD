#ifndef __ARRAY_STACK_H__

#define __ARRAY_STACK_H__

#include "data.h"

#define MAX_ARRAY_STACK_LEN 1000

typedef struct
{
    data_t array[MAX_ARRAY_STACK_LEN];
    int len;
} array_stack_t;

int array_push(array_stack_t *stack, data_t data);
int array_pop(array_stack_t *stack, data_t *data);
int array_print(array_stack_t *stack);

#endif // __ARRAY_STACK_H__