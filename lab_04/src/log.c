#include "../inc/errors.h"
#include "../inc/log.h"

char *get_err_name(int err)
{
    switch (err)
    {
        case ERR_FULL_STACK:
            return "ERR_FULL_STACK";
        case ERR_EMPTY_STACK:
            return "ERR_EMPTY_STACK";
        case ERR_ACTION:
            return "ERR_ACTION";
        case ERR_READ_STRING:
            return "ERR_READ_STRING";
        case ERR_STRING_SIZE:
            return "ERR_STRING_SIZE";
        case ERR_EMPTY_STRING:
            return "ERR_EMPTY_STRING";
        case ERR_SPACE:
            return "ERR_SPACE";
        case ERR_WORDS_COUNT:
            return "ERR_WORDS_COUNT";
        case ERR_FULL_FREE_AREAS:
            return "ERR_FULL_FREE_AREAS";
        case ERR_EMPTY_FREE_AREAS:
            return "ERR_EMPTY_FREE_AREAS";
        default:
            return "unknown err";
    }
}
