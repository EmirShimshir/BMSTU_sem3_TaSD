#include "read.h"
#include "../inc/countries.h"
#include <stdio.h>
#include <string.h>

int read_table(FILE *f, char *filename, country_t *country, size_t *count)
{
    f = fopen(filename, "r");
    if (f == NULL)
        return EXIT_FAILURE;

    *count = 0;
    while (!read_country(f, &country[*count]))
        (*count)++;

    fclose(f);
    printf("count: %zu", *count);

    return EXIT_SUCCESS;
}

int read_country(FILE *f, country_t *country)
{
    if (fscanf(f, "%s", country->country) != 1)
        return  EXIT_FAILURE;
    if (fscanf(f, "%d", &(country->count_people)) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%s", country->capital) != 1)
        return  EXIT_FAILURE;
    if (fscanf(f, "%s", country->mainland) != 1)
        return  EXIT_FAILURE;
    if (fscanf(f, "%d", &(country->need_PCR)) != 1)
        return EXIT_FAILURE;

    char temp_tourism[MAX_FIELD];
    if (fscanf(f, "%s", temp_tourism) != 1)
    {
        return EXIT_FAILURE;
    }
    else
    {
        if (strcmp(temp_tourism, "Excursion"))
        {
            if(read_excursion(f, country))
            {
                return EXIT_FAILURE;
            }
        }
        else if (strcmp(temp_tourism, "Beach"))
        {
            if(read_beach(f, country))
            {
                return EXIT_FAILURE;
            }
        }
        else if  (strcmp(temp_tourism, "Sport"))
        {
            if(read_sport(f, country))
            {
                return EXIT_FAILURE;
            }
        }
        else
        {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int read_excursion(FILE *f, country_t *country)
{
    country->tourism = EXCURSION;
    if (fscanf(f, "%d", &(country->more_info).excursion.count_objects) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%s", country->more_info.excursion.excursion_type) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int read_beach(FILE *f, country_t *country)
{
    country->tourism = BEACH;
    if (fscanf(f, "%s", country->more_info.beach.beach_type) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(country->more_info).beach.temperature_air) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(country->more_info).beach.temperature_water) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(country->more_info).beach.time_flight) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int read_sport(FILE *f, country_t *country)
{
    country->tourism = SPORT;
    if (fscanf(f, "%s", country->more_info.sport.sport_type) != 1)
        return EXIT_FAILURE;
    if (fscanf(f, "%d", &(country->more_info).sport.price_min) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void read_table_key(country_t *country, country_key_t *country_key, size_t count)
{
    for(size_t i = 0; i < count; i++)
    {
        (country_key + i)->index = i + 1;
        (country_key + i)->count_people = (country + i)->count_people;
    }
}
