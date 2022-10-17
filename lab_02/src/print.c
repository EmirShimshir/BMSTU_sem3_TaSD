#include <stdio.h>

#include "../inc/print.h"
#include "../inc/defs.h"

void print_table(country_t *country, size_t count)
{
    print_table_head();
    for (size_t i = 0; i < count; i++)
        print_country(country[i], i + 1);
}

void print_country(country_t country, size_t count)
{
    printf("|%*zu|", 5, count);
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
    print_line();

}

void print_info(void)
{
    printf("\n"
           "Shimshir Emirdzan IU7-33B var-24\n"
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
           "4 - Show all countries on chosen mainland with chosen sport activity type\n"
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

void print_rules_add(void)
{
    printf("\n"
           "When you enter country to table:\n"
           "The country, capital, mainland, excursion type, beach season and sport type should be written in one word and max len is 15 symbols.\n"
           "Other parameters of country are integer numbers.\n"
           "Please enter them without spaces and letters.\n"
           "\n");
}

void print_rules_del(void)
{
    printf("\n"
           "Enter the people count of country, that you want to delete: ");
}

void print_line(void)
{
    printf("|-----|---------------|---------------|---------------|---------------|---------------|---------------|%s---------------%s|%s---------------%s|%s---------------%s|%s---------------%s|%s---------------%s|%s---------------%s|%s---------------%s|%s---------------%s|\n",
           REDT, NORMALT, REDT, NORMALT, GREENT, NORMALT, GREENT, NORMALT, GREENT, NORMALT, GREENT, NORMALT, BLUET, NORMALT, BLUET, NORMALT
           );
}
void print_table_head(void)
{
    print_line();
    printf("|  №  |    country    |  count people |    capital    |   mainland    |   need PCR    |    tourism    | %sexcursion type%s| %scount objects%s |  %sbeach season%s |    %stemp air%s   |   %stemp water%s  |  %stime flight%s  |   %ssport type%s  |    %smin price%s  |\n",
           REDT, NORMALT, REDT, NORMALT, GREENT, NORMALT, GREENT, NORMALT, GREENT, NORMALT, GREENT, NORMALT, BLUET, NORMALT, BLUET, NORMALT
    );
    print_line();
}

void print_table_key(country_key_t *key_arr, size_t count)
{
    printf("|---|---------------|---------------|\n"
           "| № |     index     |  people count |\n"
           "|---|---------------|---------------|\n");
    for(size_t i = 0; i < count; i++)
    {
        printf("|%*zu|", 3, i + 1);
        printf("%*d|", 15, (key_arr + i)->index);
        printf("%*d|\n", 15, (key_arr + i)->count_people);
        printf("|---|---------------|---------------|\n");
    }
}