#include <stdio.h>

#include "../inc/free_areas.h"
#include "../inc/errors.h"
#include "../inc/log.h"

int add_area(free_areas_t *array, list_stack_t *ptr)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (array->len == MAX_AREAS_NUM)
    {
        err = ERR_FULL_FREE_AREAS;
        LOG_ERROR(err);
        return err;
    }

    array->array[array->len] = ptr;
    array->len++;

    LOG_INFO("finish successfully");
    return err;
}

void shift(free_areas_t *array, int index)
{
    LOG_INFO("started");
    array->len--;

    for (int i = index; i < array->len; i++)
        array->array[i] = array->array[i + 1];
    LOG_INFO("finish successfully");
}

int delete_area(free_areas_t *array, list_stack_t *ptr)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;


    if (!array->len)
    {
        err = ERR_EMPTY_FREE_AREAS;
        LOG_ERROR(err);
        return err;
    }

    for (int i = 0; i < array->len; i++)
    {
        if (array->array[i] == ptr)
        {
            shift(array, i);
            break;
        }
    }

    LOG_INFO("finish successfully");
    return err;
}

int print_free_areas(free_areas_t *array)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    if (!array->len)
    {
        err = ERR_EMPTY_FREE_AREAS;
        LOG_ERROR(err);
        return err;
    }

    printf("\nАдреса освобожденных областей:\n");
    for (int i = 0; i < array->len; i++)
        printf("%p\n", (void *) array->array[i]);


    LOG_INFO("finish successfully");
    return err;
}
