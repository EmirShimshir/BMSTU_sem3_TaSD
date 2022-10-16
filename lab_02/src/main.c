#include <string.h>

#include "../inc/countries.h"
#include "../inc/print.h"
#include "../inc/read.h"
#include "../inc/debug.h"
#include "../inc/menu.h"
#include "../inc/defs.h"

int main(const int argc, const char **argv)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    FILE *f = NULL;
    char filename[MAX_FILENAME];

    err = parse_args(argc, argv, filename);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    size_t count = 0;
    country_t country_arr[MAX_TABLE];
    country_key_t key_arr[MAX_TABLE];

    err = read_table(f, filename, country_arr, &count);
    if (err != EXIT_SUCCESS)
    {
        LOG_ERROR(err);
        return err;
    }

    read_table_key(country_arr, key_arr, count);

    int key = 0;
    print_info();
    do
    {
        print_menu();

        if(scanf("%d", &key) != 1)
        {
            err = ERR_KEY;
            printf("\nError key, please, try again according the rules\n");

            LOG_ERROR(err);
            return err;
        }

        LOG_DEBUG("got key == %d", key);

        if (key == 0)
        {
            printf("\nExit successfully\n");
            LOG_INFO("done successfully");
            return err;
        }

        err = check_key(key, country_arr, key_arr, &count);
    }
    while(err == EXIT_SUCCESS);

    LOG_ERROR(err);
    return err;
}
