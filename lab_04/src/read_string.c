#include <string.h>

#include "../inc/read_string.h"
#include "../inc/errors.h"
#include "../inc/log.h"

void remove_new_line(char *target)
{

}

int read_string(FILE *f, char *target, size_t max_target_len)
{
    if (fgets(target, max_target_len + 2, f) == NULL)
        return ERR_READ_STRING;

    if ((strlen(target) == max_target_len + 1) && (target[max_target_len] != '\n'))
        return ERR_STRING_SIZE;

    target[strlen(target) - 1] = '\0';

    if (strlen(target) == 0)
        return ERR_EMPTY_STRING;

    return EXIT_SUCCESS;
}

void clear_stdin(void)
{
    char ch;
    do
    {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}