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
    printf("%*d|", 15, country.need_PCR);
    if (country.tourism == EXCURSION) {
        printf("\x1B[31m%*s\x1B[0m|", 15, "Excursion");
        printf("\x1B[31m%*d\x1B[0m|", 15, country.more_info.excursion.count_objects);
        printf("\x1B[31m%*s\x1B[0m|", 15, country.more_info.excursion.excursion_type);
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");

    } else if (country.tourism == BEACH) {
        printf("\x1B[32m%*s\x1B[0m|", 15, "Beach");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("\x1B[32m%*s\x1B[0m|", 15, country.more_info.beach.beach_type);
        printf("\x1B[32m%*d\x1B[0m|", 15, country.more_info.beach.temperature_air);
        printf("\x1B[32m%*d\x1B[0m|", 15, country.more_info.beach.temperature_water);
        printf("\x1B[32m%*d\x1B[0m|", 15, country.more_info.beach.time_flight);
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
    } else if (country.tourism == SPORT) {
        printf("\x1B[34m%*s\x1B[0m|", 15, "Sport");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("%*s|", 15, "-");
        printf("\x1B[34m%*s\x1B[0m|", 15, country.more_info.sport.sport_type);
        printf("\x1B[34m%*d\x1B[0m|", 15, country.more_info.excursion.count_objects);
    }
    printf("\n");
}
