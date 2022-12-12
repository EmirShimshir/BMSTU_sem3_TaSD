#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "../inc/tree.h"
#include "../inc/constants.h"
#include "../inc/errors.h"
#include "../inc/time.h"
#include "../inc/hash.h"

int get_hash(char *word, const int size)
{
    int hash = 0;
//    int pow = 1;

//    for (size_t i = 0; i < strlen(word); i++)
//    {
//        hash += (word[i] + 1) * pow;
//        pow *= P;
//    }

    for (size_t i = 0; i < strlen(word); i++)
        hash += (int)word[i];
    
    return hash % size;
}


int hash_table_init(hash_table_t *table, const int table_size)
{
    table->count = table_size;
    table->array = calloc(sizeof(hash_t *), table_size);

    if (!table->array)
        return ALLOCATE_ERROR;

    return OK;
}


int push(hash_t **list, char *word)
{
    hash_t *elem = malloc(sizeof(hash_t));

    if (!elem)
        return ALLOCATE_ERROR;

    hash_t tmp = { .next = *list };
    hash_t *cur = &tmp;

    for (; cur && cur->next; cur = cur->next)
    {
        if (!strcmp(word, cur->word))
        {
            free(elem);
            return OK;
        }
    }
    
    if (!strcmp(word, cur->word))
    {
        free(elem);
        return OK;
    }

    strcpy(elem->word, word);
    elem->next = cur->next;
    cur->next = elem;
    *list = (!*list) ? elem : *list;    

    return OK;
}

int add_word_to_hash_table(hash_table_t *result, char *word)
{
    int index = get_hash(word, result->count);

    if (index < 0)
        index *= (-1);
    push(&result->array[index], word);

    return OK;
}

int create_hash_table(FILE *file, hash_table_t *result)
{
    char word[WORD_SIZE];

    for (int i = 0; i < result->count; i++)
    {
        fgets(word, WORD_SIZE, file);

        if (word[strlen(word) - 1] == '\n')
            word[strlen(word) - 1] = '\0';

        add_word_to_hash_table(result, word);
    }

    fseek(file, 0L, SEEK_SET);
    return OK;
}

void print_list(hash_t *list)
{
    for (hash_t *cur = list; cur; cur = cur->next)
        printf(" %5s -> ", cur->word);
    
    printf("│\n");
}

void print_table(hash_table_t *table)
{
    if (!table->count)
        puts("Хеш-таблица пуста!");

    for (int i = 0; i < table->count; i++)
    {
        hash_t *tmp = table->array[i];

        if (tmp != NULL)
        {
            printf("%3d: ", i);

            while (tmp != NULL)
            {
                printf(" %s -> ", tmp->word);
                tmp = tmp->next;
            }
            printf(" NULL\n");
        }
        else
            printf("%3d:  NULL\n", i);
    }
}

long int find_table_size(hash_table_t *table)
{
    long int size = 0;

    size += sizeof(table->count);
    size += sizeof(table->array);

    for (int i = 0; i < table->count; i++)
    {
        hash_t *tmp = table->array[i];

        if (tmp != NULL)
        {
            size += sizeof(tmp->word);
            size += sizeof(tmp->next);

            while (tmp != NULL)
            {
                tmp = tmp->next;
            }
        }
    }

    return size;
}

void free_list(hash_t **head)
{
    if (!head)
        return;

    for (hash_t *cur = *head; cur; )
    {
        hash_t *next = cur->next;
        free(cur);
        cur = next;
    }

    *head = NULL;
}

void free_table(hash_table_t *table)
{
    for (int i = 0; i < table->count; i++)
    {
        free_list(&table->array[i]);
    }

    free(table->array);
}

hash_t *hash_find_in_table(hash_table_t *hash_table, char *word, int collision, int *code, int *cmp)
{
    int count_collision = 0;
    int key = get_hash(word, hash_table->count);

    if (key < 0)
        key *= (-1);
    hash_t *tmp = hash_table->array[key];

    while (tmp != NULL)
    {
        count_collision++;
        (*cmp)++;
        if (strcmp(tmp->word, word) == 0)
            break;
        tmp = tmp->next;
    }

    if (count_collision > collision)
        *code = RESTRUCT;
    else if (tmp == NULL)
        *code = NOT_FOUND;

    return tmp;
}


hash_t *hash_find_time(hash_table_t *hash_table, char *word, int *cmp, uint64_t *time, int *code, int collision)
{
    int count_collision = 0;

    int key = get_hash(word, hash_table->count);

    if (key < 0)
        key *= (-1);

    hash_t *tmp = hash_table->array[key];

    uint64_t start = get_time_ticks();

    while (tmp != NULL)
    {
        (*cmp)++;
        count_collision++;

        if (strcmp(tmp->word, word) == 0)
            break;

        tmp = tmp->next;
    }

    *time += get_time_ticks() - start;

    if (count_collision > collision)
        *code = RESTRUCT;
    else if (tmp == NULL)
        *code = NOT_FOUND;
    return tmp;
}


int restructuring(FILE *file, hash_table_t *table)
{
    int new_size = table->count * 2 + 1;

    if (new_size < table->count)
        return ALLOCATE_ERROR;

    free_table(table);

    hash_table_init(table, new_size);

    create_hash_table(file, table);

    return OK;
}
