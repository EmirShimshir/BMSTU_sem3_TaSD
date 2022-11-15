#ifndef __TREE__

#define __TREE__

#include "defs.h"

typedef struct node_t
{
    char word[MAX_STR_LEN + 1];
    int height;

    struct node_t *left;
    struct node_t *right;
} node_t;

/*
* Функция очищает дерево
*
* Принимает указатель на корень дерева
*/
void free_tree(node_t *tree);

/*
* Функция создает узел дерева
*
* Принимает слово и глубину, возвращает указатель на новый узел
*/
node_t *tree_init_node(char *word, int height);

/*
* Функция добавляет новый узел в дерево
*
* Принимает указатель на корень, слово, указатель на глубину, указатель на количество сравнений
*/
node_t *tree_insert_node(node_t *tree, char *word, int *height, int *comp);

/*
* Функция печатает дерево на экран
*
* Принимает указатель на корень и количество отступов
*/
void print_tree(node_t *tree, int place);

#endif // __TREE__