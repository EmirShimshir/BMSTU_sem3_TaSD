#include "print.h"

void print_msg_start()
{
    printf("%s",
           "Шимшир Эмирджан, ИУ7-33Б, В-24\n\n"
           "Поиск произведение длинного целого\n"
           "числа на длинное вещественное число.\n\n"
           "Пробелы, лидирующие и конечные нули при вводе игнорируются.\n"
           "Пустой ввод корректен и является вводом нуля\n"
           "Вещественное число, начинающееся с \"E\" или \"e\" некорректно\n"
           "Формат ввода целого числа: ±n, длина(n) ≤ 30, знак + необязателен.\n"
           "Формат ввода вещественного числа: ±n.m E ±K, длина(n+m) ≤ 30, длина(k) ≤ 5, знак + необязателен.\n"
           );
}

void print_msg_read_int()
{
    printf("%s", "Введите целый множитель: ");
}

void print_msg_read_double()
{
    printf("%s", "Введите вещественный множитель: ");
}

void print_msg_print_double()
{
    printf("%s", "Результат умножения двух чисел: ");
}

void print_double(double_t number)
{
    print_msg_print_double();

    printf("%c0.", number.sign);
    for (int i = number.point_place; i < number.len_num; i++)
    {
        printf("%c", number.num[i]);
    }

    printf(" E %+d\n", number.order);
}

int print_error(int err)
{
    switch (err) {
        case ERR_WRONG_CHAR:
            printf("%s\n", "При вводе использован некорректный символ.");
            return ERR_WRONG_CHAR;
        case ERR_WRONG_LEN:
            printf("%s\n", "Превышено максимальное количество символов.");
            return ERR_WRONG_LEN;
        case ERR_EMPTY_MANTISSA:
            printf("%s\n", "Перед экспонентой необходмо ввести мантиссу.");
            return ERR_EMPTY_MANTISSA;
        case ERR_READ_ORDER:
            printf("%s\n", "Ошибка при чтении порядка.");
            return ERR_READ_ORDER;
        case ERR_READ_INT_STR:
            printf("%s\n", "При вводе использован некорректный символ.");
            return ERR_READ_INT_STR;
        case ERR_TOO_BIG_ORDER:
            printf("%s\n", "Переполнение порядка при выполнении умножения.");
            return ERR_TOO_BIG_ORDER;
        default:
            return EXIT_SUCCESS;
    }
}
