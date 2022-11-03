#include "errors.h"
#include "log.h"

char *get_err_name(int err)
{
    switch (err)
    {
        case ERR_MEM_ALLOC:
            return "ERR_MEM_ALLOC";
        case ERR_INPUT_ROW:
            return "ERR_INPUT_ROW";
        case ERR_INPUT_COLUMN:
            return "ERR_INPUT_COLUMN";
        case ERR_INPUT_DATA:
            return "ERR_INPUT_DATA";
        case ERR_MEM_REALLOC:
            return "ERR_MEM_REALLOC";
        case ERR_INPUT_DEGREE:
            return "ERR_INPUT_DEGREE";
        default:
            return "unknown err";
    }
}
