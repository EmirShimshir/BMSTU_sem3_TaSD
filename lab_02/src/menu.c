#include "../inc/menu.h"
#include "../inc/print.h"
#include "../inc/debug.h"
#include "../inc/add_del_country.h"
#include "../inc/defs.h"
#include "../inc/find_countries.h"
#include "../inc/sort_countries.h"
#include "../inc/read.h"
#include "../inc/compare.h"

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
        case 3:
        {
            if (*count == 0)
            {
                printf("\nYou can't delete country, because table is empty\n");
                break;
            }
            print_rules_del();
            size_t n = *count;
            int count_people = 0;
            if ((scanf("%d", &count_people) != 1) || (count_people < 1))
            {
                printf("\nError count people of country. Please write positive integer\n");
                LOG_ERROR(ERR_READ_COUNT_PEOPLE);
                return ERR_READ_COUNT_PEOPLE;
            }
            del_country(country_arr, count, count_people);
            if (n == *count)
                printf("No countries with this count people.\n");
            else
                printf("Successfully deleted\n");
            break;
        }
        case 4:
        {
            print_rules_find();
            err = find_countries(country_arr, *count);
            if (err != EXIT_SUCCESS)
            {
                LOG_ERROR(err);
                return err;
            }

            break;
        }
        case 5:
        {
            print_table_key(key_arr, *count);
            break;
        }
        case 6:
        {
            sort_table_key(key_arr, *count);
            print_table_key(key_arr, *count);
            break;
        }
        case 7:
        {
            qsort_table_key(key_arr, *count);
            print_table_key(key_arr, *count);
            break;
        }
        case 8:
        {
            sort_table(country_arr, *count);
            print_table(country_arr, *count);
            read_table_key(country_arr, key_arr, *count);
            break;
        }
        case 9:
        {
            qsort_table(country_arr, *count);
            print_table(country_arr, *count);
            read_table_key(country_arr, key_arr, *count);
            break;
        }
        case 10:
        {
            sort_table_key(key_arr, *count);
            print_sort_table_by_key(country_arr, *count, key_arr);
            break;
        }
        case 11:
        {
            qsort_table_key(key_arr, *count);
            print_sort_table_by_key(country_arr, *count, key_arr);
            break;
        }
        case 12:
        {
            compare_sort(country_arr, *count, key_arr);
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
