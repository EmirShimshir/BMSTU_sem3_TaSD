#include "multiply.h"

int multiply_numbers(int_t *int_num, double_t *double_num, double_t *result_num)
{
    short int first_len = int_num->len_num - 1;
    short int second_len = double_num->len_num;
    short int max_result_len = first_len + second_len;

    result_num->len_num = max_result_len > MAX_DOUBLE_LEN ? MAX_DOUBLE_LEN : max_result_len;
    result_num->point_place = 0;
    result_num->order = first_len + double_num->order;

    if (int_num->num[0] == double_num->sign)
        result_num->sign = '+';
    else
        result_num->sign = '-';

    short int transfer = 0;
    short int shift = 0;
    char last = '\0';

    for (short int i = 0; i < max_result_len; i++)
    {
        short int index;
        if (i >= MAX_DOUBLE_LEN)
            index = 0;
        else
            index = result_num->len_num - i - 1;

        short int current_sum = 0;

        for (short int k = 0; k < second_len; k++)
        {
            short int second_digit = double_num->num[second_len - k - 1] - '0';

            short int first_digit;

            if (i - k >= 0 && i - k < first_len)
                first_digit = int_num->num[first_len - i + k] - '0';
            else
                first_digit = 0;

            current_sum += first_digit * second_digit;
        }
        current_sum += transfer;

        transfer = current_sum / 10;

        if (i >= MAX_DOUBLE_LEN && current_sum)
        {
            shift++;
            last = result_num->num[MAX_DOUBLE_LEN - 1];

            for (short int j = MAX_DOUBLE_LEN - 1; j > 0; j--)
                result_num->num[j] = result_num->num[j - 1];
        }

        result_num->num[index] = current_sum % 10 + '0';
    }

    if (last != '\0')
        round_num(result_num, last);
    normalize_number(result_num);

    if (result_num->order > 99999 || result_num->order < -99999)
        return ERR_TOO_BIG_ORDER;

    return EXIT_SUCCESS;
}

void round_num(double_t *number, char last)
{
    short int transfer = 0;
    short int i = number->len_num - 1;

    while (i >= 0 && (last >= '5' || transfer))
    {
        last = '\0';
        if (number->num[i] == '9')
        {
            number->num[i] = '0';
            transfer = 1;
        }
        else
        {
            number->num[i]++;
            transfer = 0;
        }

        i--;
    }

    if (transfer)
    {
        for (short int j = MAX_DOUBLE_LEN - 1; j > 0; j--)
            number->num[j] = number->num[j - 1];

        number->order++;
    }
}
