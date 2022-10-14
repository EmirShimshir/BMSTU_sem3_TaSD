#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../inc/menu.h"
#include "../inc/add_del.h"
#include "../inc/read.h"
#include "../inc/print.h"
#include "../inc/compare.h"
#include "../inc/countries.h"

int main(void)
{
    FILE *f = NULL;
    char *filename = "./data/countries_50.txt";
    int key;
    size_t count = 0;
    int error = 0;

    country_t country_arr[MAX_TABLE + 1];
    country_key_t key_arr[MAX_TABLE + 1];

    if(read_table(f, filename, country_arr, &count))
        return EXIT_FAILURE;

    read_table_key(country_arr, key_arr, count);
    print_info();
    print();


    if(scanf("%d", &key) != 1)
    {
        printf("\nError key, please, try again according the rules\n");
        return ERROR_KEY;
    }
    if (key == 0)
        return EXIT_SUCCESS;

    while(!(error = check_key(key, country_arr, &count, key_arr, filename)))
    {
        print();
        if(scanf("%d", &key) != 1)
        {
            printf("\nError key, please, try again according the rules\n");
            return ERROR_KEY;
        }
        if (key == 0)
            return EXIT_SUCCESS;
    }
    return error;

}
