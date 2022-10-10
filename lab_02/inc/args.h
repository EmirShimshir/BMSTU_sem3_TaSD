#ifndef UNIVERSAL_MENU_ARGS_H
#define UNIVERSAL_MENU_ARGS_H

#include "macro_magic.h" //required header
#include "cars.h"

ARG_PACKER(button_01, car_table_t *table);
ARG_PACKER(button_02, car_table_t *table);
ARG_PACKER(button_03, car_table_t *table);
ARG_PACKER(button_04, car_table_t *table);
ARG_PACKER(button_05, car_table_t *table, car_key_table_t *keys);
ARG_PACKER(button_06, car_table_t *table, car_table_t *sorted_table);
ARG_PACKER(button_07, car_table_t *table, car_key_table_t *keys);
ARG_PACKER(button_08, car_table_t *table, car_key_table_t *keys);
ARG_PACKER(button_09, car_table_t *table, car_key_table_t *keys);
ARG_PACKER(button_10, car_table_t *table);

#endif //UNIVERSAL_MENU_ARGS_H
