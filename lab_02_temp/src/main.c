#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FIELD 15
#define MAX_TABLE 200

typedef enum tourism
{
    EXCURSION,
    BEACH,
    SPORT
} tourism_t;

typedef struct
{
    char excursion_type[MAX_FIELD];
    int count_objects;
} excursion_t;

typedef struct
{
    char beach_type[MAX_FIELD];
    int temperature_air;
    int temperature_water;
    int time_flight;
} beach_t;

typedef struct
{
    char sport_type[MAX_FIELD];
    int price_min;
} sport_t;


typedef union
{
    excursion_t excursion;
    beach_t beach;
    sport_t sport;
} info_t;

typedef struct
{
    char country[MAX_FIELD];
    char capital[MAX_FIELD];
    char mainland[MAX_FIELD];
    int count_people;
    int need_PCR;
    tourism_t tourism;
    info_t more_info;
} country_t;

typedef struct
{
    int index;
    int count_people;
} country_key_t;

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

void print_table(country_t *country, size_t count)
{
    for (size_t i = 0; i < count; i++)
        print_country(country[i], i + 1);
}

int main(void)
{

    FILE *f = NULL;
    char *filename = "./data/countries_200.txt";
    size_t count = 0;
    int error = 0;

    country_t country_arr[MAX_TABLE + 1];
    country_key_t key_arr[MAX_TABLE + 1];

    if(read_table(f, filename, country_arr, &count))
        return EXIT_FAILURE;

    read_table_key(country_arr, key_arr, count);

    print_table(country_arr, count);
    return error;

}
