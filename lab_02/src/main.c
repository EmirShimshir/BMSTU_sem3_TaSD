#include "../inc/menu.h"
#include "countries.h"
#include "../inc/errors.h"
#include "../inc/print.h"

int main(void)
{
    LOG_INFO("started");
    int err = EXIT_SUCCESS;

    print_start_msg();

    country_table_t table;
    table.len = 0;

    while (1)
    {
        print_menu_msg();

        int action; // -?
        err = choose_action(&action);
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(get_err_name(err));
            print_error_msg(err);
            continue;
            // return err;
        }

        err = do_action(action, &table);
        if (err != EXIT_SUCCESS)
        {
            LOG_ERROR(get_err_name(err));
            print_error_msg(err);
            continue;
            // return err;
        }
    }

    LOG_INFO("done successfully");
    return err;
}