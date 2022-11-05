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
        case ERR_INPUT_COLUMNS:
            return "ERR_INPUT_COLUMNS";
        case ERR_INPUT_NON_ZERO:
            return "ERR_INPUT_NON_ZERO";
        case ERR_INPUT_ELEM:
            return "ERR_INPUT_ELEM";
        case ERR_INPUT_PRINT_METHOD:
            return "ERR_INPUT_PRINT_METHOD";
        case ERR_MATRIX_NOT_ALLOCATED:
            return "ERR_MATRIX_NOT_ALLOCATED";
        case ERR_DIFF_MATRIX_SIZE:
            return "ERR_DIFF_MATRIX_SIZE";
        default:
            return "unknown err";
    }
}
