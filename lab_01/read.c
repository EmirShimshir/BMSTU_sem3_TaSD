#include "read.h"

int read_double(double_t *number)
{
    int err = EXIT_SUCCESS;

    print_msg_read_double();

    err = read_mantissa(number);
    if (err == FINISH_INPUT)
    {
        err = EXIT_SUCCESS;
        normalize_number(number);

        return err;
    }
    if (err != EXIT_SUCCESS)
        return err;

    err = read_order(&number->order);
    if (err != EXIT_SUCCESS)
        return err;

    normalize_number(number);

    return err;
}

int read_mantissa(double_t *number)
{
    char ch;
    _Bool begin = true;
    _Bool point_flag = false;
    _Bool zeros_delete_flag = true;
    short int current_point_place = 0;
    number->sign = '+';
    number->len_num = 0;
    number->order = 0;

    while ((ch = getchar()) != 'e' && ch != 'E' && ch != '\n' && ch != EOF)
    {
        if (ch == ' ')
            continue;

        if (!begin && zeros_delete_flag && '0' == ch)
            continue;

        if (begin)
        {
            if ('-' == ch || '+' == ch)
            {
                number->sign = ch;
                begin = false;
                continue;
            }

            else if ((ch < '0' || ch > '9') && ch != '.')
                return ERR_WRONG_CHAR;

            begin = false;
        }

        if (point_flag)
            current_point_place++;

        if (ch == '.')
        {
            if (point_flag)
            {
                return ERR_WRONG_CHAR;
            }
            point_flag = true;
            zeros_delete_flag = false;
        }

        else if (ch < '0' || ch > '9')
            return ERR_WRONG_CHAR;

        else
        {
            if (number->len_num >= MAX_DOUBLE_LEN)
                return ERR_WRONG_LEN;
            number->num[number->len_num] = ch;
            number->len_num++;
            zeros_delete_flag = false;
        }
    }

    number->point_place = number->len_num - current_point_place;

    if (0 == number->len_num)
    {
        number->num[0] = '0';
        number->len_num++;
    }

    if (!number->len_num && !point_flag)
        return ERR_EMPTY_MANTISSA;

    if (ch != 'e' && ch != 'E')
        return FINISH_INPUT;

    return EXIT_SUCCESS;
}

int read_int_str(char *read_str, short int *count, int max_int_len)
{
    char ch;
    *count = 0;
    _Bool zeros_flag = true;

    while ((ch = getchar()) != '\n' && ch != EOF && *count < max_int_len + 1)
    {
        if (ch == ' ')
            continue;

        if ('0' == ch && *count > 1 && zeros_flag)
            continue;

        if (ch < '0' || ch > '9')
        {
            if (*count != 0 || (0 == *count && ch != '-' && ch != '+'))
                return ERR_READ_INT_STR;
        }

        if (0 == *count && ch != '-' && ch != '+')
            read_str[(*count)++] = '+';

        if (ch != '0' && zeros_flag)
        {
            zeros_flag = false;

            if (*count > 1)
                (*count)--;
        }
        read_str[(*count)++] = ch;
    }

    if (*count > max_int_len)
        return ERR_WRONG_LEN;

    read_str[*count] = '\0';

    return EXIT_SUCCESS;
}

int read_order(int *order)
{
    int err = EXIT_SUCCESS;

    char read_order[MAX_ORDER_LEN + 1];
    short int len_order = 0;
    err = read_int_str(read_order, &len_order, MAX_ORDER_LEN);
    if (err != EXIT_SUCCESS)
        return ERR_READ_ORDER;

    char *end_ptr;

    *order = strtol(read_order, &end_ptr, 10);

    if (end_ptr == read_order || *end_ptr != '\0')
        return ERR_READ_ORDER;

    return EXIT_SUCCESS;
}

void normalize_number(double_t *number)
{
    short int back_zeros = 0;

    number->order += number->point_place;
    number->point_place = 0;

    if (1 == number->len_num && '0' == number->num[0])
    {
        number->order = 0;
        return;
    }

    short int count;

    for (count = 0; count < number->len_num && '0' == number->num[count]; count++);

    for (short int i = count; i < number->len_num; i++)
        number->num[i - count] = number->num[i];

    number->order -= count;
    number->len_num -= count;

    for (count = 0; count < number->len_num; count++)
    {
        if ('0' == number->num[count])
            back_zeros++;
        else
            back_zeros = 0;
    }

    number->len_num -= back_zeros;

    if (0 == number->len_num)
    {
        number->num[0] = '0';
        number->len_num++;
        number->order = 0;
    }
}

int read_int(int_t *number)
{
    int err = EXIT_SUCCESS;
    print_msg_start();
    print_msg_read_int();

    err = read_int_str(number->num, &(number->len_num), MAX_INT_LEN + 1);

    return err;
}
