#include <stdio.h>

#include "../inc/num_pop.h"
#include "../inc/log.h"
#include "../inc/errors.h"
#include "../inc/time.h"
#include "../inc/read_string.h"
#include "../inc/free_areas.h"

int array_num_pop(array_stack_t *array_stack)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!array_stack->len)
    {
        err = ERR_EMPTY_STACK;
        LOG_ERROR(err);
        return err;
    }

    int words_count;

    printf("Введите колчество слов: \n");
    if (scanf("%d", &words_count) != 1)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    clear_stdin();

    if (words_count < 1 || words_count > array_stack->len)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    unsigned long long time_beg, time_end, time_res = 0;
    data_t data;
    for (int i = 0; i < words_count; i++)
    {
        time_beg = microseconds_now();
        err = array_pop(array_stack, &data);
        time_end = microseconds_now();
        time_res += time_end - time_beg;
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            return err;
        }
        printf("слово %s, длиной %d успешно удалено\n", data.word, data.len_word);
    }

    printf("\nВремя работы (в микросекундах): %llu\n", time_res);

    LOG_INFO("finish successfully");
    return err;
}

int list_num_pop(list_stack_t **list_stack, free_areas_t *ptrs)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!*list_stack)
    {
        err = ERR_EMPTY_STACK;
        LOG_ERROR(err);
        return err;
    }

    int words_count;

    printf("Введите колчество слов: \n");
    if (scanf("%d", &words_count) != 1)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    clear_stdin();

    if (words_count < 1 || words_count > (*list_stack)->index + 1)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    unsigned long long time_beg, time_end, time_res = 0;
    data_t data;
    for (int i = 0; i < words_count; i++)
    {
        add_area(ptrs, *list_stack);
        time_beg = microseconds_now();
        err = list_pop(list_stack, &data);
        time_end = microseconds_now();
        time_res += time_end - time_beg;
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            return err;
        }
        printf("слово %s, длиной %d успешно удалено\n", data.word, data.len_word);
    }

    printf("\nВремя работы (в микросекундах): %llu\n", time_res);

    LOG_INFO("finish successfully");
    return err;
}