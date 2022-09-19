#ifndef __TYPES_H__

#define __TYPES_H__

#include "defs.h"

typedef struct
{
    char num[MAX_INT_LEN + 1];
    short int len_num;
} int_t;

typedef struct
{
    char sign;
    char num[MAX_DOUBLE_LEN];
    short int len_num;
    short int point_place;
    int order;
} double_t;

#endif // __TYPES_H__
