#ifndef __ARRAY_STACK_H__

#define __ARRAY_STACK_H__

#include "data.h"

#define MAX_ARRAY_STACK_LEN 1000

typedef struct
{
    data_t array[MAX_ARRAY_STACK_LEN];
    int len;
} array_stack_t;

/*
* Функция push для стека на массиве
*
* Принимает указатель на стек на массиве
* Принимает указатель на структуру с данными,
* которую необходимо добавить в стек
*/
int array_push(array_stack_t *stack, data_t data);

/*
* Функция pop для стека на массиве
*
* Принимает указатель на стек на массиве
* Принимает указатель на структуру с данными,
* которую необходимо удалить из стека
*/
int array_pop(array_stack_t *stack, data_t *data);

/*
* Функция вывода стека на списке
*
* Принимает указатель на начало списка
*/
int array_print(array_stack_t *stack);

#endif // __ARRAY_STACK_H__