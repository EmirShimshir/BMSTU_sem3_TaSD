#include <string.h>
#include <stdbool.h>

#include "../inc/read_words.h"
#include "../inc/read_string.h"
#include "../inc/time.h"
#include "../inc/log.h"
#include "../inc/errors.h"

int array_read_words(array_stack_t *array_stack)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    int words_count;

    printf("Введите колчество слов (до 1000 cлов): \n");
    if (scanf("%d", &words_count) != 1)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    clear_stdin();

    if (words_count < 1 || words_count > MAX_ARRAY_STACK_LEN - array_stack->len)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    unsigned long long time_beg, time_end, time_res = 0;
    char temp_word[MAX_WORD_LEN + 2];
    data_t data;

    for (int i = 0; i < words_count; i++)
    {
        printf("Введите %d слово (до 10 символов без пробелов): \n", i + 1);
        err = read_string(stdin, temp_word, MAX_WORD_LEN);
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            printf("Ошибка ввода %d слова, попробуйте ещё раз\n", i + 1);
            i--;
            continue;
        }
        strncpy(data.word, temp_word, MAX_WORD_LEN + 1);
        data.len_word = strlen(temp_word);

        time_beg = microseconds_now();
        err = array_push(array_stack, data);
        time_end = microseconds_now();
        time_res += time_end - time_beg;
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            return err;
        }
        printf("слово %s, длиной %d успешно добавлено\n", data.word, data.len_word);
    }

    printf("\nВремя работы (в микросекундах): %llu\n", time_res);


    LOG_INFO("finish successfully");
    return err;
}

int list_read_words(list_stack_t **list_stack, free_areas_t *ptrs)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    int words_count;

    printf("Введите колчество слов (до 1000 cлов): \n");
    if (scanf("%d", &words_count) != 1)
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    clear_stdin();

    if (words_count < 1 || words_count > MAX_LIST_STACK_LEN - ((*list_stack) ? (*list_stack)->index + 1 : 0))
    {
        err = ERR_WORDS_COUNT;
        LOG_ERROR(err);
        return err;
    }

    unsigned long long time_beg, time_end, time_res = 0;
    char temp_word[MAX_WORD_LEN + 2];
    data_t data;

    for (int i = 0; i < words_count; i++)
    {
        printf("Введите %d слово (до 10 символов без пробелов): \n", i + 1);
        err = read_string(stdin, temp_word, MAX_WORD_LEN);
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            printf("Ошибка ввода %d слова, попробуйте ещё раз\n", i + 1);
            i--;
            continue;
        }
        strncpy(data.word, temp_word, MAX_WORD_LEN + 1);
        data.len_word = strlen(temp_word);

        time_beg = microseconds_now();
        err = list_push(list_stack, data);
        time_end = microseconds_now();
        time_res += time_end - time_beg;
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(err);
            return err;
        }
        delete_area(ptrs, *list_stack);

        printf("Адрес узла: %p, слово: %10s, длина слова: %2d\n", (void *) (*list_stack), (*list_stack)->data.word, (*list_stack)->data.len_word);
        printf("слово %d успешно добавлено\n", i + 1);
    }

    printf("\nВремя работы (в микросекундах): %llu\n", time_res);


    LOG_INFO("finish successfully");
    return err;
}