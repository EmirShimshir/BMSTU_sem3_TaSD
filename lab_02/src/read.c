#include <stdio.h>
#include <string.h>
#include <stdlib.h> // EXIT_FAILURE

#include "../inc/read.h"

int read_table(FILE *f, char *filename, country_t *country, size_t *count)
{
    f = fopen(filename, "r");
    if (f == NULL)
        return EXIT_FAILURE;

    *count = 0;
    while (!read_country(f, &country[*count]))
        (*count)++;

    fclose(f);

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

int read_country(FILE *f, country_t *country)
{
    if (fscanf(f, "%s", country->country) != 1)
    {
        printf("1!\n");
        return  EXIT_FAILURE;
    }

    if (fscanf(f, "%d", &(country->count_people)) != 1)
    {
        printf("test: %s\n", country->country);
        printf("2!\n");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%s", country->capital) != 1)
    {
        printf("3!\n");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%s", country->mainland) != 1)
    {
        printf("4!\n");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->need_PCR)) != 1)
    {
        printf("5!\n");
        return  EXIT_FAILURE;
    }

    char temp_tourism[MAX_FIELD];
    if (fscanf(f, "%s", temp_tourism) != 1)
    {
        printf("6!\n");
        return  EXIT_FAILURE;
    }
    else
    {
        printf("!%s!\n", temp_tourism);
        printf("strcmp: %d\n", strcmp(temp_tourism, "Excursion"));
        if (strcmp(temp_tourism, "Excursion") == 0)
        {
            if(read_excursion(f, country))
            {
                printf("7!\n");
                return  EXIT_FAILURE;
            }
        }
        else if (strcmp(temp_tourism, "Beach") == 0)
        {
            if(read_beach(f, country))
            {
                printf("8!\n");
                return  EXIT_FAILURE;
            }
        }
        else if  (strcmp(temp_tourism, "Sport") == 0)
        {
            if(read_sport(f, country))
            {
                printf("9!\n");
                return  EXIT_FAILURE;
            }
        }
        else
        {
            printf("10!\n");
            return  EXIT_FAILURE;
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
    {
        printf("5!\n");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).beach.temperature_air) != 1)
    {
        printf("6!\n");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).beach.temperature_water) != 1)
    {
        printf("7!\n");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).beach.time_flight) != 1)
    {
        printf("8!\n");
        return  EXIT_FAILURE;
    }

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
