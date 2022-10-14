#include "print.h"
#include "../inc/countries.h"

void print_table_rama()
{
    printf("|---|---------------|----------------|---------------|-------|\
------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
    printf("| № |    Страна    |   Население   |    Столица    | Материк |\
 ПЦР | Вид туризма Excursion/Beach/Sport | Кол-во объектов/Основной сезон/Вид спорта | Основной вид/Температура воздуха/Стоимость отдыха | -/Температура воды/- | -/Время полёта/- |\n");
    printf("|---|---------------|----------------|---------------|-------|\
------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
}

void print_table(country_t *country, size_t count)
{
    print_table_rama();
    for (size_t i = 0; i < count; i++)
        print_country(country[i], i + 1);
}

//void print_table_key(country_key_t *key_arr, size_t count)
//{
//    printf("|---|--------|--------|\n");
//    printf("| № | index  | square |\n");
//    printf("|---|--------|--------|\n");
//    for(size_t i = 0; i < count; i++)
//    {
//        printf("|%*zu|", 3, i + 1);
//        printf("%*d|", 8, (key_arr + i)->index);
//        printf("%*d|\n", 8, (key_arr + i)->square);
//        printf("|---|--------|--------|\n");
//    }
//}

void print_country(country_t country, size_t count)
{
    printf("|%*zu|", 3,  count);
    printf("%*s|", 15, country.country);
    printf("%*d|", 15, country.count_people);
    printf("%*s|", 15, country.capital);
    printf("%*s|", 15, country.mainland);
    printf("%*d|", 15, country.need_PCR);
    if (country.tourism == EXCURSION)
    {
        printf("%*s|", 15, "Excursion");
        printf("%*d|", 15, country.more_info.excursion.count_objects);
        printf("%*s|", 15, country.more_info.excursion.excursion_type);
    }
    else if (country.tourism == BEACH)
    {
        printf("%*s|", 15, "Beach");
        printf("%*s|", 15, country.more_info.beach.beach_type);
        printf("%*d|", 15, country.more_info.beach.temperature_air);
        printf("%*d|", 15, country.more_info.beach.temperature_water);
        printf("%*d|", 15, country.more_info.beach.time_flight);
    }
    else if (country.tourism == BEACH)
    {
        printf("%*s|", 15, "Beach");
        printf("%*s|", 15, country.more_info.sport.sport_type);
        printf("%*d|", 15, country.more_info.excursion.count_objects);

    }



//    printf("%*s|", 15, flat.address.country);
//    printf("%*s|", 16, flat.address.city);
//    printf("%*s|", 15, flat.address.street);
//    printf("%*d|", 7,flat.address.num_house);
//    printf("%*d|", 6, flat.address.num_flat);
//    printf("%*d|", 8, flat.square);
//    printf("%*d|", 6, flat.room_number);
//    printf("%*d|", 11, flat.cost_square_meter);
//    if (!flat.is_primary)
//    {
//        printf("%s|", "  +  ");
//        if (flat.primary.is_fishing)
//            printf("%s|","    -    ");
//        else
//            printf("%s|", "    +    ");
//        printf("       |            |             |      |\n");
//    }
//    else
//    {
//        printf("%s|", "  -  ");
//        printf("%s|","         ");
//        printf("%*d|",7, flat.primary.secondary.year);
//        printf("%*d|",12, flat.primary.secondary.all_owners);
//        printf("%*d|",13,flat.primary.secondary.count_last_owners);
//        if (!flat.primary.secondary.animals)
//            printf("  +   |\n");
//        else
//            printf("  -   |\n");
//
//
//    }

    printf("\n|---|---------------|----------------|---------------|-------\
|------|--------|------|-----------|-----|---------|-------|------------|-------------|------|\n");
}

void print_info(void)
{
    printf("Типы и Структуры Данных, Л/Р №2, Обработка списка стран, Шимшир Эмирджан ИУ7-33Б\n");
}

void print(void) {
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
           "\n");
}

//void print_rules_add(void)
//{
//    printf("\nWhen you enter the flat to table:\n\
//The city, street and country should be written in one word and max len is 15 symbols.\n\
//Parametrs of flat are integer numbers.\
//Please enter them without spaces and letters.\n\n");
//}
//
//void print_rules_del(void)
//{
//    printf("\nEnter the square of flats, that you want to delete:");
//}
