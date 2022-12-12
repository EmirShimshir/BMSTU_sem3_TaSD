#ifndef __TREE_DDP_H__
#define __TREE_DDP_H__

#include <stdio.h>

#include "tree.h"

int create_tree(tree_t **root, FILE *f_in, int *count);

/*
* Функция создает узел дерева
*
* Принимает слово и глубину, возвращает указатель на новый узел
*/
tree_t *create_node(char *word, int h);

/*
* Функция очищает дерево
*
* Принимает указатель на корень дерева
*/
void free_tree(tree_t *tree);

/*
* Функция ищет слово в дереве
*
* Принимает указатель на корень дерева, слово и указатель на количество сравнений
*/
int find_tree(tree_t *tree, char *word, int *count_cmp);


#endif // __TREE_DDP_H__
