#include <stdio.h>

#include "../inc/print_reversed.h"
#include "../inc/time.h"

void print_popped_reversed(array_stack_t *array_stack, list_stack_t **list_stack)
{
    printf("Стек на массиве\n");
    if (array_stack->len == 0)
        printf("Пустой стек\n");
    else
        array_print_reversed(array_stack);
    printf("Стек на cписке\n");
    if (!(*list_stack))
        printf("Пустой стек\n");
    else
        list_print_reversed(list_stack);
}

void print_word_reversed(char *word, int len_word)
{
    for (int i = len_word - 1; i >= 0; i--)
        printf("%c", word[i]);
    printf("\n");
}

void array_print_reversed(array_stack_t *stack)
{
    array_stack_t temp_stack = {.len = 0};
    data_t temp_data;

    unsigned long long time_beg, time_end, time_res;

    time_beg = microseconds_now();
    while (stack->len)
    {

        print_word_reversed(stack->array[stack->len - 1].word, stack->array[stack->len - 1].len_word);
        array_pop(stack, &temp_data);
        array_push(&temp_stack, temp_data);
    }

    while (temp_stack.len)
    {
        array_pop(&temp_stack, &temp_data);
        array_push(stack, temp_data);
    }
    time_end = microseconds_now();
    time_res = time_end - time_beg;

    printf("\nВремя работы (в микросекундах): %llu\n", time_res);
    printf("Память (в байтах): %ld\n", sizeof(*stack));
}

void list_print_reversed(list_stack_t **stack)
{
    list_stack_t *temp_stack = NULL;
    data_t temp_data;

    unsigned long long time_beg, time_end, time_res;

    time_beg = microseconds_now();
    while (*stack)
    {
        print_word_reversed((*stack)->data.word, (*stack)->data.len_word);
        list_pop(stack, &temp_data);
        list_push(&temp_stack, temp_data);
    }

    while (temp_stack)
    {
        list_pop(&temp_stack, &temp_data);
        list_push(stack, temp_data);

    }
    time_end = microseconds_now();
    time_res = time_end - time_beg;

    printf("\nВремя работы (в микросекундах): %llu\n", time_res);
    printf("Память (в байтах): %ld\n", sizeof(list_stack_t) * ((*stack)->index + 1));
}
