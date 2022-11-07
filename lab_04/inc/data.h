#ifndef __DATA_H__

#define __DATA_H__

#define MAX_WORD_LEN 10

typedef struct
{
    int len_word;
    char word[MAX_WORD_LEN + 1];
} data_t;

#endif // __DATA_H__