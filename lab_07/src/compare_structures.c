#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/tree_avl.h"
#include "../inc/tree_ddp.h"
#include "../inc/hash.h"
#include "../inc/time.h"
#include "../inc/compare_structures.h"

static int file_len(FILE *f);
static char **fill_words(FILE *f, int n);
static int tree_count(tree_t *tree, char **words, int n, int *cmp);
static int hash_count_time(hash_table_t *hash_table,  char **words, int n, int *cmp);
static void count_for_file(FILE *f, tree_t *tree, tree_t *balance, hash_table_t *table, int n);
static int file_count(FILE *f, char **words, int n, int *cmp);

int compare_structures(void)
{
    printf("\n\nСрeднее время поиска слова:\n\n");

    tree_t *tree = NULL;
    tree_t *balance = NULL;
    hash_table_t table;
    int count = 0;
    FILE *file;

    printf("| Количество элементов  |        ДДП           |   Сбалансированное   |      Хеш-таблица     |        Файл          |\n");

    int n = 50;
    file = fopen("./func_tests/test_50.txt", "r");
    create_tree(&tree, file, &count);
    rewind(file);
    create_tree_avl(&balance, file);
    rewind(file);
    hash_table_init(&table, count);
    create_hash_table(file, &table);
    printf("|         %d            |", n);
    count_for_file(file, tree, balance, &table, n);
    free_tree(tree);
    free_tree(balance);
    free_table(&table);

    n = 100;
    file = fopen("./func_tests/test_100.txt", "r");
    tree = NULL;
    balance = NULL;
    create_tree(&tree, file, &count);
    rewind(file);
    create_tree_avl(&balance, file);
    rewind(file);
    hash_table_init(&table, count);
    create_hash_table(file, &table);
    printf("|         %d           |", n);
    count_for_file(file, tree, balance, &table, n);
    free_tree(tree);
    free_tree(balance);
    free_table(&table);


    n = 500;
    file = fopen("./func_tests/test_500.txt", "r");
    tree = NULL;
    balance = NULL;
    create_tree(&tree, file, &count);
    rewind(file);
    create_tree_avl(&balance, file);
    rewind(file);
    hash_table_init(&table, count);
    create_hash_table(file, &table);
    printf("|         %d           |", n);
    count_for_file(file, tree, balance, &table, n);
    free_tree(tree);
    free_tree(balance);
    free_table(&table);


    n = 1000;
    file = fopen("./func_tests/test_1000.txt", "r");
    tree = NULL;
    balance = NULL;
    create_tree(&tree, file, &count);
    rewind(file);
    create_tree_avl(&balance, file);
    rewind(file);
    hash_table_init(&table, count);
    create_hash_table(file, &table);
    printf("|         %d          |", n);
    count_for_file(file, tree, balance, &table, n);
    free_tree(tree);
    free_tree(balance);
    free_table(&table);

    return OK;
}

int file_bytes(FILE *f)
{
    rewind(f);
    fseek(f, 0, SEEK_END);
    unsigned size = ftell(f);
    rewind(f);

    return size;
}

int search_file(char *to_find, FILE *f, int *cmp)
{
    rewind(f);

    int i = 0;
    char buffer[WORD_SIZE];

    while (fgets(buffer, WORD_SIZE, f) != NULL)
    {
        i++;
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        (*cmp)++;
        if (strcmp(to_find, buffer) == 0)
        {
            return OK;
        }
    }

    rewind(f);
    return NOT_FOUND;
}

static int file_len(FILE *f)
{
    rewind(f);

    int lines = 0;
    char buffer[WORD_SIZE];

    while (fgets(buffer, WORD_SIZE, f) != NULL)
        lines++;

    rewind(f);

    return lines;
}



static char **fill_words(FILE *f, int n)
{
    rewind(f);
    unsigned long file_len = file_bytes(f);

    int ind = 0;
    char buffer[WORD_SIZE];
    char **words = (char **)malloc(sizeof(char *) * n);
    for (unsigned long i = 0; i < file_len; ++i)
    {
        words[i] = (char *)malloc(sizeof(char) * WORD_SIZE);
    }

    while (fgets(buffer, WORD_SIZE, f) != NULL && ind < n)
    {
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }

        strcpy(words[ind], buffer);
        ind++;
    }

    rewind(f);

    return words;
}

static int tree_count(tree_t *tree, char **words, int n, int *cmp)
{
    uint64_t start, stop, time = 0;

    *cmp = 0;

    start =  get_time_ticks();

    for (int i = 0; i < n; i++)
        find_tree(tree, words[i], cmp);

    stop = get_time_ticks();
    time = stop - start;

    return time / n;
}

static int hash_count_time(hash_table_t *hash_table,  char **words, int n, int *cmp)
{
    uint64_t time = 0;
    int code;
    *cmp = 0;
    int collisions = 4;


    for (int i = 0; i < n; i++)
        hash_find_time(hash_table, words[i], cmp, &time, &code, collisions);
    
    return time / n;
}

static int file_count(FILE *f, char **words, int n, int *cmp)
{
    uint64_t start, stop, time = 0;

    *cmp = 0;

    start = get_time_ticks();

    for (int i = 0; i < n; i++)
    {
        search_file(words[i], f, cmp);
    }

    stop = get_time_ticks();
    time = stop - start;

    return time / n;
}


static void count_for_file(FILE *f, tree_t *tree, tree_t *balance, hash_table_t *table, int n)
{
    char **words = fill_words(f, n);
    int time = 0;
    int cmp;
    unsigned long flen = file_len(f);

    time = tree_count(tree, words, flen, &cmp);
    printf("%20d  |", time);

    time = 0;
    time = tree_count(balance, words, flen, &cmp);
    printf("%20d  |", time);

    time = 0;
    time = hash_count_time(table, words, flen, &cmp);
    printf("%20d  |", time);
    rewind(f);

    time = 0;
    time = file_count(f, words, n, &cmp);
    printf("%20d  |\n", time);

    for (int i = 0; i < n; i++)
        free(words[i]);
    free(words);

    fclose(f);
}
