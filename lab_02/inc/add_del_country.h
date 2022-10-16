#ifndef __ADD_DEL_COUNTRY_H__
#define __ADD_DEL_COUNTRY_H__

#include <stdlib.h>

#include "countries.h"

#define ERR_MAX_TABLE 3
#define ERR_READ_COUNTRY 4
#define ERR_READ_COUNT_PEOPLE 5
#define ERR_READ_CAPITAL 6
#define ERR_READ_MAINLAND 7
#define ERR_READ_NEED_PCR 8
#define ERR_READ_TOURISM 9
#define ERR_READ_COUNT_OBJECTS 10
#define ERR_READ_EXCURSION_TYPE 11
#define ERR_READ_BEACH_SEASON 12
#define ERR_READ_TEMP_AIR 13
#define ERR_READ_TEMP_WATER 14
#define ERR_READ_TIME_FLIGHT 15
#define ERR_READ_SPORT_TYPE 16
#define ERR_READ_PRICE_MIN 17
#define ERR_TOURISM_TYPE 18

int add_country(country_t *country_arr, country_key_t *key_arr, size_t *count);

#endif // __ADD_DEL_COUNTRY_H__
