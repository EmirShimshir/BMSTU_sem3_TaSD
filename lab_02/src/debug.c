#include "../inc/debug.h"
#include "../inc/defs.h"


char *get_err_name(int err)
{
    switch (err)
    {
        case EXIT_FAILURE:
            return "EXIT_FAILURE";
        case ERR_KEY:
            return "ERR_KEY";
        case ERR_MAX_TABLE:
            return "ERR_MAX_TABLE";
        case ERR_READ_COUNTRY:
            return "ERR_READ_COUNTRY";
        case ERR_READ_CAPITAL:
            return "ERR_READ_CAPITAL";
        case ERR_READ_MAINLAND:
            return "ERR_READ_MAINLAND";
        case ERR_READ_NEED_PCR:
            return "ERR_READ_NEED_PCR";
        case ERR_READ_TOURISM:
            return "ERR_READ_TOURISM";
        case ERR_READ_COUNT_OBJECTS:
            return "ERR_READ_COUNT_OBJECTS";
        case ERR_READ_EXCURSION_TYPE:
            return "ERR_READ_EXCURSION_TYPE";
        case ERR_READ_BEACH_SEASON:
            return "ERR_READ_BEACH_SEASON";
        case ERR_READ_TEMP_AIR:
            return "ERR_READ_TEMP_AIR";
        case ERR_READ_TEMP_WATER:
            return "ERR_READ_TEMP_WATER";
        case ERR_READ_TIME_FLIGHT:
            return "ERR_READ_TIME_FLIGHT";
        case ERR_READ_SPORT_TYPE:
            return "ERR_READ_SPORT_TYPE";
        case ERR_READ_PRICE_MIN:
            return "ERR_READ_PRICE_MIN";
        case ERR_TOURISM_TYPE:
            return "ERR_TOURISM_TYPE";
        default:
            return "unknown err";
    }
}