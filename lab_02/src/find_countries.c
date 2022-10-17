#include <stdio.h>
#include <string.h>

#include "../inc/debug.h"
#include "../inc/find_countries.h"
#include "../inc/add_del_country.h"
#include "../inc/print.h"

int find_countries(country_t *country_arr, size_t count)
{
    char mainland[MAX_FIELD + 2];
    printf("Enter the mainland: ");
    getchar();
    if ((fgets(mainland, MAX_FIELD + 2, stdin) == NULL) || trim(mainland))
    {
        printf("Error mainland. Please try again according the rules\n");
        LOG_ERROR(ERR_READ_MAINLAND);
        return ERR_READ_MAINLAND;
    }

    char sport_type[MAX_FIELD + 2];
    printf("Enter sport type: ");
    if ((fgets(sport_type, MAX_FIELD + 2, stdin) == NULL) || trim(sport_type))
    {
        printf("Error sport type. Please try again according the rules\n");
        LOG_ERROR(ERR_READ_SPORT_TYPE);
        return ERR_READ_SPORT_TYPE;
    }

    printf("Table of all countries on chosen mainland with chosen sport activity type.\n");
    printf("Mainland is: %s\n", mainland);
    printf("Sport type is: %s\n\n", sport_type);
    print_table_head();

    int n = 1;
    int flag = 0;
    for (size_t i = 0; i < count; i++)
    {
        if ((strcmp((country_arr + i)->mainland, mainland) == 0) &&
            ((country_arr + i)->tourism == SPORT) &&
            (strcmp((country_arr + i)->more_info.sport.sport_type, sport_type) == 0))
        {
            flag = 1;
            print_country(*(country_arr + i), n++);
        }
    }
    if (!flag)
    {
        printf("|                                                                                                  %sEMPTY TABLE%s                                                                                                                        |\n",
               REDD, NORMALD);
        print_line();

    }
    return EXIT_SUCCESS;
}
