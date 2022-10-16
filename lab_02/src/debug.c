#include <stdlib.h> // EXIT_FAILURE

#include "../inc/debug.h"

char *get_err_name(int err)
{
    switch (err)
    {
        case EXIT_FAILURE:
            return "EXIT_FAILURE";
        default:
            return "unknown err";
    }
}