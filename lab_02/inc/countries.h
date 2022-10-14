#ifndef __COUNTRIES_H__
#define __COUNTRIES_H__

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
    char capital[MAX_FIELD;
    char mainland[MAX_FIELD];
    int count_people;
    int need_PCR;
    tourism_t tourism;
    info_t more_info;
} country_t;

typedef struct
{
    country_t table[MAX_TABLE];
    size_t len;
} country_table_t;

typedef struct
{
    int index;
    int count_people;
} country_key_t;

typedef struct
{
    car_key_t table[MAX_TABLE];
    size_t len;
} car_key_table_t;

#endif // __COUNTRIES_H__
