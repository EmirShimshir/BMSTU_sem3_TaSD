#include <stdlib.h>

#include "../inc/array_stack.h"
#include "../inc/errors.h"
#include "../inc/log.h"

int array_push(array_stack_t *stack, data_t data)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (stack->len == MAX_ARRAY_STACK_LEN)
    {
        err = ERR_FULL_STACK;
        LOG_ERROR(err);
        return err;
    }

    stack->array[stack->len] = data;
    stack->len++;

    LOG_INFO("finish successfully");
    return err;
}

int array_pop(array_stack_t *stack, data_t *data)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!stack->len)
    {
        err = ERR_EMPTY_STACK;
        LOG_ERROR(err);
        return err;
    }

    stack->len--;
    *data = stack->array[stack->len];

    LOG_INFO("finish successfully");
    return err;
}

int array_print(array_stack_t *stack)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!stack->len)
    {
        err = ERR_EMPTY_STACK;
        LOG_ERROR(err);
        return err;
    }

    array_stack_t temp_stack = {.len = 0};
    data_t temp_data;
    while (stack->len)
    {
        printf("слово: %10s, длина слова: %2d\n", stack->array[stack->len - 1].word, stack->array[stack->len - 1].len_word);

        array_pop(stack, &temp_data);
        array_push(&temp_stack, temp_data);
    }

    while (temp_stack.len)
    {
        array_pop(&temp_stack, &temp_data);
        array_push(stack, temp_data);
    }

    printf("\nПамять (байт): %ld\n", sizeof(*stack));

    LOG_INFO("finish successfully");
    return err;
}
