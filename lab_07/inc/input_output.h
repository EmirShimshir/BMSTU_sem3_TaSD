#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include "tree.h"
#include "constants.h"
#include "errors.h"

void print_conditions(void);

void print_menu(void);

void input_rules(void);

int input_command(int *command);

#endif