#include <stdio.h>

#include "../inc/constants.h"
#include "../inc/errors.h"
#include "../inc/io.h"

void input_rules(void)
{
    printf("Программа для работы с бинарным, сбалансированным деревьями и хеш-таблицей.\n"
           "Элементами структур данных являются слова.\n"
           "Программа осуществляет поиск введенного слова.\n"
           "\n"
           "Шимшир Эмирджан ИУ7-33Б\n"
           "\n"
           "(При вводе пункта меню необходимо вводить только числа)\n"
           "(Слова необходимо вводить на английском языке)\n"
           "(Длина вводимых слов должна быть не более 20 символов)\n"
           "(Пробелы и знаки препинания не допускаются)\n"
           "\n");
}

void print_menu(void)
{
    printf("%s",
           "\nВыберите номер пункта меню:\n"
           "1) Ввести данные из файла\n"
           "2) Вывести ДДП\n"
           "3) Вывести АВЛ-дерево\n"
           "4) Вывести хеш-таблицу\n"
           "5) Найти слово в ДДП, сбалансированном дереве, хеш-таблице и файле\n"
           "0) Выход\n\n"
           "Введите команду: ");
}


void clean_input_stream()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}


int input_command(int *command)
{
    int code = scanf("%d", command);

    if (code)
        code += (*command >= END && *command <= SEARCH);

    while (code != 2)
    {
        printf("\nКоманда введена неверно. Введите еще раз: \n");
        code = 0;
        code = scanf("%d", command);

        if (code)
            code += (*command >= END && *command <= SEARCH);
    }

    return OK;
}

int input_element(int *element)
{
    if (scanf("%d", element) != 1)
    {
        clean_input_stream();
        return INPUT_ERROR;
    }

    return OK;
}
