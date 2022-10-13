#include <stdio.h>

void print_start_msg(void)
{
    printf("Типы и Структуры Данных, Л/Р №2, Обработка списка стран, Шимшир Эмирджан ИУ7-33Б\n");
}

void print_menu_msg(void)
{
    printf("\n"
           "          МЕНЮ\n"
           "\n"
           "1  - Загрузить таблицу стран из файла\n"
           "2  - Просмотреть таблицу\n"
           "3  - Добавить информацию о новой стране в конец таблицы\n"
           "4  - Удалить страны из списка по цене\n"
           "5  - Просмотреть отсортированную по цене таблицу ключей\n"
           "6  - Вывести упорядоченную по цене таблицу\n"
           "7  - Вывести таблицу в упорядоченном по цене виде по упорядоченной таблице ключей\n"
           "8  - Сравнить эффективность работы программы способами 6 и 7\n"
           "9  - Сравнить время работы сортировок (пирамидальной и вставками)\n"
           "10 - Вывести цены не новых машин указанной марки\n"
           "     с одним предыдущим собственником, отстутсвием ремонта\n"
           "     в указанном диапазоне цен\n"
           "0  - Выход\n"
           "\n")
}