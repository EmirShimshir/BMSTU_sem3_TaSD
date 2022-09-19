#include "types.h"
#include "read.h"
#include "print.h"
#include "multiply.h"

int main(void)
{
    int err = EXIT_SUCCESS;

    int_t num_int;
    err = read_int(&num_int);
    if (err != EXIT_SUCCESS)
        return print_error(err);

    double_t num_double;
    err = read_double(&num_double);
    if (err != EXIT_SUCCESS)
        return print_error(err);

    double_t result;
    err = multiply_numbers(&num_int, &num_double, &result);
    if (err != EXIT_SUCCESS)
        return print_error(err);

    print_double(&result);

    return print_error(err);
}
