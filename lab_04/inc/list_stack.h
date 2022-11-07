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

/*
* Функция push для стека на списке
*
* Принимает указатель на начало списка
* Принимает указатель на структуру с данными,
* которую необходимо добавить в стек
*/
int list_push(list_stack_t **stack, data_t data);

/*
* Функция pop для стека на списке
*
* Принимает указатель на начало списка
* Принимает указатель на структуру с данными,
* которую необходимо удалить из стека
*/
int list_pop(list_stack_t **stack, data_t *data);

/*
* Функция вывода стека на списке
*
* Принимает указатель на начало списка
*/
int list_print(list_stack_t **stack);

#endif // __LIST_STACK_H__