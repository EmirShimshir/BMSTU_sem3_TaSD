#include "errors.h"
#include "log.h"

char *get_err_name(int err)
{
    switch (err)
    {
        case ERR_MEM_ALLOC:
            return "ERR_MEM_ALLOC";
        case ERR_ACTION:
            return "ERR_ACTION";
        case ERR_INPUT_ROWS:
            return "ERR_INPUT_ROWS";
        default:
            return "unknown err";
    }
}
