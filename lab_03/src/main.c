#include "../inc/matrix.h"

#include <stdio.h>

int main(void)
{
    matrix_t matrix = NULL;
    destroy(matrix);
    matrix = create(5, 5);

    matrix_print(matrix);

    printf("%lu\n", sizeof(matrix));

    destroy(matrix);
}