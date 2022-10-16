#ifndef __MANU_H__
#define __MANU_H__

#include <stdlib.h>

#include "countries.h"

#define ERR_KEY 2

int check_key(int key, country_t *country_arr, country_key_t *key_arr, size_t *count);

#endif // __MANU_H__