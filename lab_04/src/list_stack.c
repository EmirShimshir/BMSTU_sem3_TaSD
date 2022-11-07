#include <stdlib.h>

#include "../inc/list_stack.h"
#include "../inc/errors.h"
#include "../inc/log.h"

int list_push(list_stack_t **stack, data_t data)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (*stack && (*stack)->index + 1 == MAX_LIST_STACK_LEN)
    {
        err = ERR_FULL_STACK;
        LOG_ERROR(err);
        return err;
    }

    list_stack_t *node = malloc(sizeof(list_stack_t));
    node->data = data;
    node->index = (*stack) ? (*stack)->index + 1 : 0;
    node->next = *stack;
    *stack = node;

    LOG_INFO("finish successfully");
    return err;
}

int list_pop(list_stack_t **stack, data_t *data)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!*stack)
    {
        err = ERR_EMPTY_STACK;
        LOG_ERROR(err);
        return err;
    }

    list_stack_t *popped_node = *stack;
    *stack = (*stack)->next;

    *data = popped_node->data;
    free(popped_node);

    LOG_INFO("finish successfully");
    return err;
}

int list_print(list_stack_t **stack)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!*stack)
    {
        err = ERR_EMPTY_STACK;
        LOG_ERROR(err);
        return err;
    }

    list_stack_t *temp_stack = NULL;
    data_t temp_data;
    printf("Старый стек\n");
    while (*stack)
    {
        printf("Адрес узла: %p, слово: %10s, длина слова: %2d\n", (void *) (*stack), (*stack)->data.word, (*stack)->data.len_word);
        list_pop(stack, &temp_data);
        list_push(&temp_stack, temp_data);
    }

    printf("Новый стек\n");
    while (temp_stack)
    {
        list_pop(&temp_stack, &temp_data);
        list_push(stack, temp_data);
        printf("Адрес узла: %p, слово: %10s, длина слова: %2d\n", (void *) (*stack), (*stack)->data.word, (*stack)->data.len_word);

    }

    printf("\nПамять (байт): %ld\n", sizeof(list_stack_t) * ((*stack)->index + 1));

    LOG_INFO("finish successfully");
    return err;
}
