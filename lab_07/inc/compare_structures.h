#ifndef COMPARE_STRUCTURES_H
#define COMPARE_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/tree_avl.h"
#include "../inc/tree_ddp.h"
#include "../inc/hash.h"
#include "../inc/time.h"

int compare_structures(void);

int search_file(char *to_find, FILE *f, int *cmp);

int file_bytes(FILE *f);

#endif