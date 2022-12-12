#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "tree.h"
#include "constants.h"
#include "errors.h"
#include "time.h"

typedef struct hash_t
{
    char word[WORD_SIZE];
    struct hash_t *next;
} hash_t;

typedef struct hash_table_t
{
    int count;
    hash_t **array;
} hash_table_t;

int hash_table_init(hash_table_t *table, const int table_size);

int create_hash_table(FILE *file, hash_table_t *result);

void print_table(hash_table_t *table);

void free_table(hash_table_t *table);

int restructuring(FILE *file, hash_table_t *table);

hash_t *hash_find_in_table(hash_table_t *hash_table, char *word, int collision, int *code, int *cmp);

hash_t *hash_find_time(hash_table_t *hash_table, char *word, int *cmp, unsigned long long *time, int *code, int collision);

long int find_table_size(hash_table_t *table);

#endif