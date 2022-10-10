#include <string.h>
#include <stdio.h>

#include "my_string.h"

size_t my_strlen(const char *const str)
{
    size_t count = 0;
    size_t len = 0;

    while (str[count] != '\0')
    {
        len++;
        count++;

        if (str[count] < 0 || str[count] > 127)
            count++;
    }

    return len;
}

int read_str(char *const str, const int max_len, FILE *stream)
{
    if (!fgets(str, max_len, stream))
        return ERR_FGETS;

    size_t byte_len = strlen(str);

    if ('\n' == str[byte_len - 1])
        str[byte_len - 1] = '\0';
    else
    {
        clear_stdin();
        return ERR_STR_READ;
    }

    return READ_OK;
}

void clear_stdin(void)
{
    char ch;
    do
    {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
    
}