#include <stdio.h>

#include "../inc/add_del_country.h"
#include "../inc/read.h"
#include "../inc/debug.h"
#include "../inc/defs.h"
#include <string.h>
#include <ctype.h>

int trim(char *s)
{
    if (strlen(s) < 2 || s[strlen(s) - 1] != '\n')
        return EXIT_FAILURE;

    char(*s1) = s + strlen(s) - 1;

    while (isspace(*s1))
        s1--;
    *(s1 + 1) = 0;

    return EXIT_SUCCESS;
}

int read_country_stdin(country_t *country)
{
    getchar();
    printf("Enter the country: ");
    if ((fgets(country->country, MAX_FIELD + 1, stdin) == NULL) || (trim(country->country)))
    {
        printf("Error country. Please try again according the rules\n");
        LOG_ERROR(ERR_READ_COUNTRY);
        return ERR_READ_COUNTRY;
    }
    LOG_DEBUG("read country == %s", country->country);

    printf("Enter the count of people: ");
    if (scanf("%d", &(country->count_people)) != 1 || (country->count_people < 1))
    {
        printf("Error count of people. Please try again\n");
        LOG_ERROR(ERR_READ_COUNT_PEOPLE);
        return ERR_READ_COUNT_PEOPLE;
    }
    LOG_DEBUG("read count of people == %d", country->count_people);

    getchar();
    printf("Enter the capital: ");
    if ((fgets(country->capital, MAX_FIELD + 1, stdin) == NULL) || (trim(country->capital)))
    {
        printf("Error capital. Please try again according the rules\n");
        LOG_ERROR(ERR_READ_CAPITAL);
        return ERR_READ_CAPITAL;
    }
    LOG_DEBUG("read capital == %s", country->capital);

    printf("Enter the mainland: ");
    if ((fgets(country->mainland, MAX_FIELD + 1, stdin) == NULL) || trim(country->mainland))
    {
        printf("Error mainland. Please try again according the rules\n");
        LOG_ERROR(ERR_READ_MAINLAND);
        return ERR_READ_MAINLAND;
    }
    LOG_DEBUG("read mainland == %s", country->mainland);

    printf("Enter is need PCR (0 or 1): ");
    if (scanf("%d", &(country->need_PCR)) != 1 || (country->need_PCR < 0))
    {
        printf("Error need PCR. Please try again\n");
        LOG_ERROR(ERR_READ_NEED_PCR);
        return ERR_READ_NEED_PCR;
    }
    LOG_DEBUG("read need PCR == %d", country->need_PCR);

    getchar();
    char temp_tourism[MAX_FIELD];
    printf("Enter tourism (Excursion/Beach/Sport): ");
    if ((fgets(temp_tourism, MAX_FIELD + 1, stdin) == NULL) || trim(temp_tourism))
    {
        printf("Error tourism. Please try again according the rules\n");
        LOG_ERROR(ERR_READ_TOURISM);
        return ERR_READ_TOURISM;
    }
    else
    {
        LOG_DEBUG("read tourism == %s", temp_tourism);
        if (strcmp(temp_tourism, "Excursion") == 0)
        {
            country->tourism = EXCURSION;

            printf("Enter count objects: ");
            if ((scanf("%d", &(country->more_info).excursion.count_objects) != 1) || (country->more_info.excursion.count_objects < 1))
            {
                printf("Error count objects. Please try again\n");
                LOG_ERROR(ERR_READ_COUNT_OBJECTS);
                return ERR_READ_COUNT_OBJECTS;
            }
            LOG_DEBUG("read count objects == %d", country->more_info.excursion.count_objects);

            getchar();
            printf("Enter excursion type: ");
            if ((fgets(country->more_info.excursion.excursion_type, MAX_FIELD + 1, stdin) == NULL) || trim(country->more_info.excursion.excursion_type))
            {
                printf("Error excursion type. Please try again according the rules\n");
                LOG_ERROR(ERR_READ_EXCURSION_TYPE);
                return ERR_READ_EXCURSION_TYPE;
            }
            LOG_DEBUG("read excursion type == %s", country->more_info.excursion.excursion_type);
        }
        else if (strcmp(temp_tourism, "Beach") == 0)
        {
            country->tourism = BEACH;

            printf("Enter beach season: ");
            if ((fgets(country->more_info.beach.beach_type, MAX_FIELD + 1, stdin) == NULL) || trim(country->more_info.beach.beach_type))
            {
                printf("Error beach season. Please try again according the rules\n");
                LOG_ERROR(ERR_READ_BEACH_SEASON);
                return ERR_READ_BEACH_SEASON;
            }
            LOG_DEBUG("read beach season == %s", country->more_info.beach.beach_type);

            printf("Enter temperature air: ");
            if ((scanf("%d", &(country->more_info).beach.temperature_air) != 1) || (country->more_info.beach.temperature_air < 1))
            {
                printf("Error temperature air. Please try again\n");
                LOG_ERROR(ERR_READ_TEMP_AIR);
                return ERR_READ_TEMP_AIR;
            }
            LOG_DEBUG("read temperature air == %d", country->more_info.beach.temperature_air);

            printf("Enter temperature water: ");
            if ((scanf("%d", &(country->more_info).beach.temperature_water) != 1) || (country->more_info.beach.temperature_water < 1))
            {
                printf("Error temperature water. Please try again\n");
                LOG_ERROR(ERR_READ_TEMP_WATER);
                return ERR_READ_TEMP_WATER;
            }
            LOG_DEBUG("read temperature water == %d", country->more_info.beach.temperature_water);

            printf("Enter time flight: ");
            if ((scanf("%d", &(country->more_info).beach.time_flight) != 1) || (country->more_info.beach.time_flight < 1))
            {
                printf("Error time flight. Please try again\n");
                LOG_ERROR(ERR_READ_TIME_FLIGHT);
                return ERR_READ_TIME_FLIGHT;
            }
            LOG_DEBUG("read time flight == %d", country->more_info.beach.time_flight);
        }
        else if  (strcmp(temp_tourism, "Sport") == 0)
        {
            country->tourism = SPORT;

            printf("Enter sport type: ");
            if ((fgets(country->more_info.sport.sport_type, MAX_FIELD + 1, stdin) == NULL) || trim(country->more_info.sport.sport_type))
            {
                printf("Error sport type. Please try again according the rules\n");
                LOG_ERROR(ERR_READ_SPORT_TYPE);
                return ERR_READ_SPORT_TYPE;
            }
            LOG_DEBUG("read sport type == %s", country->more_info.sport.sport_type);

            printf("Enter price min: ");
            if ((scanf("%d", &(country->more_info).sport.price_min) != 1) || (country->more_info.sport.price_min < 1))
            {
                printf("Error price min. Please try again\n");
                LOG_ERROR(ERR_READ_PRICE_MIN);
                return ERR_READ_PRICE_MIN;
            }
            LOG_DEBUG("read price mint == %d", country->more_info.sport.price_min);
        }
        else
        {
            printf("Error unknown tourism type. Please try again\n");
            LOG_ERROR(ERR_TOURISM_TYPE);
            return ERR_TOURISM_TYPE;
        }
    }

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}


int add_country(country_t *country_arr, country_key_t *key_arr, size_t *count)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;
    if (*count == MAX_TABLE)
    {
        printf("\nIt is impossible to add a country, since there are %d of them at most\n", MAX_TABLE);
        LOG_ERROR(ERR_MAX_TABLE);
        return ERR_MAX_TABLE;
    }

    err = read_country_stdin(country_arr + *count);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    read_key(country_arr, key_arr, (*count)++);
    LOG_DEBUG("added country in key arr: index == %d, count people == %d", key_arr[*count - 1].index, key_arr[*count - 1].count_people);

    LOG_INFO("done successfully");
    return EXIT_SUCCESS;
}

void del_country(country_t *country_arr, size_t *count, int count_people)
{
    for(size_t i = 0; i < *count; i++)
    {
        if ((country_arr + i)->count_people == count_people) {
            swap(country_arr, count, i);
            i--;
            (*count)--;
        }
    }
}

void swap(country_t *country_arr, size_t *count, size_t i)
{
    for(size_t j = i; j < *count - 1; j++)
    {
        strncpy((country_arr + j)->country, (country_arr + j + 1)->country, MAX_FIELD - 1);
        (country_arr + j)->count_people = (country_arr + j + 1)->count_people;
        strncpy((country_arr + j)->capital, (country_arr + j + 1)->capital, MAX_FIELD - 1);
        strncpy((country_arr + j)->mainland, (country_arr + j + 1)->mainland, MAX_FIELD - 1);
        (country_arr + j)->need_PCR = (country_arr + j + 1)->need_PCR;
        switch ((country_arr + j + 1)->tourism) {
            case EXCURSION:
                strncpy((country_arr + j)->more_info.excursion.excursion_type, (country_arr + j + 1)->more_info.excursion.excursion_type, MAX_FIELD - 1);
                (country_arr + j)->more_info.excursion.count_objects = (country_arr + j + 1)->more_info.excursion.count_objects;
                break;
            case BEACH:
                strncpy((country_arr + j)->more_info.beach.beach_type, (country_arr + j + 1)->more_info.beach.beach_type, MAX_FIELD - 1);
                (country_arr + j)->more_info.beach.temperature_air = (country_arr + j + 1)->more_info.beach.temperature_air;
                (country_arr + j)->more_info.beach.temperature_water = (country_arr + j + 1)->more_info.beach.temperature_water;
                (country_arr + j)->more_info.beach.time_flight = (country_arr + j + 1)->more_info.beach.time_flight;
                break;
            case SPORT:
                strncpy((country_arr + j)->more_info.sport.sport_type, (country_arr + j + 1)->more_info.sport.sport_type, MAX_FIELD - 1);
                (country_arr + j)->more_info.sport.price_min = (country_arr + j + 1)->more_info.sport.price_min;
                break;
            default:
                LOG_ERROR(ERR_TOURISM_TYPE);
                LOG_DEBUG("i == %zu, j == %zu", i, j);
        }
    }
}