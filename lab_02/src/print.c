#include <stdio.h>

#include "../inc/print.h"

void print_table(country_t *country, size_t count)
{
    for (size_t i = 0; i < count; i++)
        print_country(country[i], i + 1);
}

void print_country(country_t country, size_t count)
{
    printf("|%*zu|", 3, count);
    printf("%*s|", 15, country.country);
    printf("%*d|", 15, country.count_people);
    printf("%*s|", 15, country.capital);
    printf("%*s|", 15, country.mainland);
    if (country.need_PCR == 0)
        printf("%*s|", 15, "NO");
    else
        printf("%*s|", 15, "YES");
    if (country.tourism == EXCURSION) {
        printf("%s%*s%s|", REDT, 15, "Excursion", NORMALT);
        printf("%s%*d%s|", REDT, 15, country.more_info.excursion.count_objects, NORMALT);
        printf("%s%*s%s|", REDT, 15, country.more_info.excursion.excursion_type, NORMALT);
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");

    } else if (country.tourism == BEACH) {
        printf("%s%*s%s|", GREENT, 15, "Beach", NORMALT);
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%s%*s%s|", GREENT, 15, country.more_info.beach.beach_type, NORMALT);
        printf("%s%*d%s|", GREENT, 15, country.more_info.beach.temperature_air, NORMALT);
        printf("%s%*d%s|", GREENT, 15, country.more_info.beach.temperature_water, NORMALT);
        printf("%s%*d%s|", GREENT, 15, country.more_info.beach.time_flight, NORMALT);
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
    } else if (country.tourism == SPORT) {
        printf("%s%*s%s|", BLUET, 15, "Sport", NORMALT);
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%s%*s%s|", BLUET, 15, country.more_info.sport.sport_type, NORMALT);
        printf("%s%*d%s|", BLUET, 15, country.more_info.excursion.count_objects, NORMALT);
    }
    printf("\n");
}

void print_info(void)
{
    printf("\n"
           "Shimshir Emirdzan IU7-33B var-22\n"
           "This programm can show you the tables with countries and sort thoose tables.\n"
           "MENU:\n"
           "\n");
}

void print_menu(void)
{
    printf("\n"
           "0 - Quit\n"
           "1 - Show country table\n"
           "2 - Add country\n"
           "3 - Delete country\n"
           "4 - Show all secondary flat with 2 rooms and animals !!change!!\n"
           "5 - Show table key by square\n"
           "6 - Show sort table key by square (bubble sort)\n"
           "7 - Show sort table key by square (quick sort)\n"
           "8 - Show sort table be square (bubble sort)\n"
           "9 - Show sort table by square (quick sort)\n"
           "10 - Show sort table by square with table (bubble sort)\n"
           "11 - Show sort table by square with table (quick sort)\n"
           "12 - Compare time for bubble sort/qsort and table/table_key \n"
           "Choose key: ");
}
