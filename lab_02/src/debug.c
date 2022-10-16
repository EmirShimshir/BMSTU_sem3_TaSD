#include <stdlib.h> // EXIT_FAILURE

#include "../inc/debug.h"
#include "../inc/menu.h"
#include "../inc/add_del_country.h"

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
        default:
            return "unknown err";
    }
}