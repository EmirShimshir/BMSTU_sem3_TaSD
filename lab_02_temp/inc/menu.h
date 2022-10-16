#ifndef __MENU_H__
#define __MENU_H__

#include "add_del.h"
#include "read.h"
#include "read.h"
#include "find.h"
#include "sort.h"
#include "print.h"
#include "compare.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR_KEY 1

int check_key(int key, country_t *country_arr, size_t *count, country_key_t *key_arr, char *filename);

#endif // __MENU_H__
