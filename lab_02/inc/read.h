#ifndef __READ_H__
#define __READ_H__

#include <stdio.h>
#include <stdlib.h>

#include "countries.h"

int parse_args(const int argc, const char **argv, char *filename);
int read_table(FILE *f, char *filename, country_t *country, size_t *count);
void read_table_key(country_t *country, country_key_t *country_key, size_t count);
void read_key(country_t *country, country_key_t *country_key, size_t count);
int read_country(FILE *f, country_t *country);
int read_excursion(FILE *f, country_t *country);
int read_beach(FILE *f, country_t *country);
int read_sport(FILE *f, country_t *country);

#endif // __READ_H__
