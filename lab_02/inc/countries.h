#ifndef __COUNTRIES_H__
#define __COUNTRIES_H__

#include "defs.h"

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

#endif // __COUNTRIES_H__
