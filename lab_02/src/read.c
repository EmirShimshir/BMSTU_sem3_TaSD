#include <stdio.h>
#include <string.h>
#include <stdlib.h> // EXIT_FAILURE

#include "../inc/read.h"
#include "../inc/debug.h"

int parse_args(const int argc, const char **argv, char *filename)
{
    LOG_INFO("started");
    if (argc == 2)
    {
        LOG_DEBUG("argv[1] == %s", argv[1]);
        strncpy(filename, argv[1], MAX_FILENAME - 1);
        LOG_DEBUG("filename == %s", filename);

        LOG_INFO("done successfully");
        return EXIT_SUCCESS;
    }

    LOG_ERROR(EXIT_FAILURE);
    return EXIT_FAILURE;
}

int read_table(FILE *f, char *filename, country_t *country, size_t *count)
{
    LOG_INFO("started");
    f = fopen(filename, "r");
    if (f == NULL)
    {
        LOG_ERROR(EXIT_FAILURE);
        return EXIT_FAILURE;
    }

    while (*count < MAX_TABLE && !read_country(f, country + *count))
    {
        (*count)++;
        LOG_DEBUG("count == %zu", *count);
    }

    if (*count == MAX_TABLE)
    {
        LOG_DEBUG("*count == MAX_TABLE == %zu", *count);
    }
    else
    {
        LOG_DEBUG("read all file, *count == %zu", *count);
        if (!feof(f))
        {
            LOG_ERROR(EXIT_FAILURE);
            return EXIT_FAILURE;
        }
    }

    fclose(f);

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}

void read_key(country_t *country, country_key_t *country_key, size_t i)
{
    (country_key + i)->index = i + 1;
    (country_key + i)->count_people = (country + i)->count_people;
}

void read_table_key(country_t *country, country_key_t *country_key, size_t count)
{
    for(size_t i = 0; i < count; i++)
        read_key(country, country_key, i);
}

int read_country(FILE *f, country_t *country)
{
    LOG_INFO("started");
    if (fscanf(f, "%s", country->country) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", country->country) != 1");
        return  EXIT_FAILURE;
    }

    if (fscanf(f, "%d", &(country->count_people)) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->count_people)) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%s", country->capital) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", country->capital) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%s", country->mainland) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", country->mainland) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->need_PCR)) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->need_PCR)) != 1");
        return  EXIT_FAILURE;
    }

    char temp_tourism[MAX_FIELD];
    if (fscanf(f, "%s", temp_tourism) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", temp_tourism) != 1");
        return  EXIT_FAILURE;
    }
    else
    {
        LOG_DEBUG("tourism == %s", temp_tourism);
        if (strcmp(temp_tourism, "Excursion") == 0)
        {
            if(read_excursion(f, country) != EXIT_SUCCESS)
            {
                LOG_DEBUG("%s", "read_excursion(f, country) != EXIT_SUCCESS");
                return  EXIT_FAILURE;
            }
        }
        else if (strcmp(temp_tourism, "Beach") == 0)
        {
            if(read_beach(f, country) != EXIT_SUCCESS)
            {
                LOG_DEBUG("%s", "read_beach(f, country) != EXIT_SUCCESS");
                return  EXIT_FAILURE;
            }
        }
        else if  (strcmp(temp_tourism, "Sport") == 0)
        {
            if(read_sport(f, country) != EXIT_SUCCESS)
            {
                LOG_DEBUG("%s", "read_sport(f, country) != EXIT_SUCCESS");
                return  EXIT_FAILURE;
            }
        }
        else
        {
            LOG_DEBUG("%s", "error tourism type");
            return  EXIT_FAILURE;
        }
    }

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}

int read_excursion(FILE *f, country_t *country)
{
    LOG_INFO("started");
    country->tourism = EXCURSION;
    if (fscanf(f, "%d", &(country->more_info).excursion.count_objects) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->more_info).excursion.count_objects) != 1");
        return  EXIT_FAILURE;
    }

    if (fscanf(f, "%s", country->more_info.excursion.excursion_type) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", country->more_info.excursion.excursion_type) != 1");
        return  EXIT_FAILURE;
    }

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}

int read_beach(FILE *f, country_t *country)
{
    LOG_INFO("started");
    country->tourism = BEACH;
    if (fscanf(f, "%s", country->more_info.beach.beach_type) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", country->more_info.beach.beach_type) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).beach.temperature_air) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->more_info).beach.temperature_air) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).beach.temperature_water) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->more_info).beach.temperature_water) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).beach.time_flight) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->more_info).beach.time_flight) != 1");
        return  EXIT_FAILURE;
    }

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}

int read_sport(FILE *f, country_t *country)
{
    LOG_INFO("started");
    country->tourism = SPORT;
    if (fscanf(f, "%s", country->more_info.sport.sport_type) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%s\", country->more_info.sport.sport_type) != 1");
        return  EXIT_FAILURE;
    }
    if (fscanf(f, "%d", &(country->more_info).sport.price_min) != 1)
    {
        LOG_DEBUG("%s", "fscanf(f, \"%d\", &(country->more_info).sport.price_min) != 1");
        return  EXIT_FAILURE;
    }

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}
