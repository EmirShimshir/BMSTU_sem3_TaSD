#include <string.h>

#include "../inc/read_string.h"
#include "../inc/errors.h"
#include "../inc/log.h"

void remove_new_line(char *target)
{
    target[strlen(target) - 1] = '\0';
}

bool is_any_space(char *target)
{
    for (size_t i = 0; i < strlen(target); i++)
        if (target[i] == ' ')
            return true;

    return false;
}

int read_string(FILE *f, char *target, size_t max_target_len)
{
    if (fgets(target, max_target_len + 2, f) == NULL)
        return ERR_READ_STRING;

    if ((strlen(target) == max_target_len + 1) && (target[max_target_len] != '\n'))
        return ERR_STRING_SIZE;

    remove_new_line(target);

    if (strlen(target) == 0)
        return ERR_EMPTY_STRING;

    if (is_any_space(target))
        return ERR_SPACE;

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