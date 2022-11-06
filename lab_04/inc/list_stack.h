#ifndef __LIST_STACK_H__

#define __LIST_STACK_H__

#include "data.h"

#define MAX_LIST_STACK_LEN 1000

typedef struct list_stack_t list_stack_t;

struct list_stack_t
{
    data_t data;

    int index;
    list_stack_t *next;
};

int list_push(list_stack_t **stack, data_t data);
int list_pop(list_stack_t **stack, data_t *data);
int list_print(list_stack_t **stack);

#endif // __LIST_STACK_H__