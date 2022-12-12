#ifndef __COMPARE_STRUCTURES_H__
#define __COMPARE_STRUCTURES_H__

#include <stdio.h>

int compare_structures(void);

int search_file(char *to_find, FILE *f, int *cmp);

int file_bytes(FILE *f);

#endif // __COMPARE_STRUCTURES_H__