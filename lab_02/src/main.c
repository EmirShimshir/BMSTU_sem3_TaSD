#include <stdlib.h>

#include "../inc/print.h"
#include "../inc/read.h"
#include "../inc/countries.h"
#include "../inc/debug.h"

int main(void)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    FILE *f = NULL;
    char *filename = "./data/countries_50.txt";

    size_t count = 0;
    country_t country_arr[MAX_TABLE + 1];
    country_key_t key_arr[MAX_TABLE + 1];

    err = read_table(f, filename, country_arr, &count);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    read_table_key(country_arr, key_arr, count);

    print_table(country_arr, count);

    LOG_INFO("done successfully");
    return err;
}
