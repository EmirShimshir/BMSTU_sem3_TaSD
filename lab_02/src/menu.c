#include "../inc/menu.h"
#include "../inc/print.h"
#include "../inc/debug.h"
#include "../inc/add_del_country.h"
#include "../inc/defs.h"

int check_key(int key, country_t *country_arr, country_key_t *key_arr, size_t *count)
{
    int err = EXIT_SUCCESS;
    LOG_INFO("started");
    switch (key)
    {
        case 1:
        {
            print_table(country_arr, *count);

            break;
        }
        case 2:
        {
            print_rules_add();
            err = add_country(country_arr, key_arr, count);
            if ((err != EXIT_SUCCESS))
            {
                LOG_ERROR(err);
                return err;
            }

            printf("\nCountry successfully added\n");

            break;
        }


        default:
        {
            err = ERR_KEY;
            printf("\nError key, please, try again according the rules\n");

            LOG_ERROR(err);
            return err;
        }
    }

    LOG_INFO("done successfully");
    return err;
}
