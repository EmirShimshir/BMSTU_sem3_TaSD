#include <stdio.h>

#include "../inc/utils.h"

void flush_input(void)
{
    char c;
    while((scanf("%c", &c) == 1) && (c != '\n'));
}