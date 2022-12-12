#ifndef __TREE_DDP_H__
#define __TREE_DDP_H__

#include <stdio.h>

#include "tree.h"

int create_tree(tree_t **root, FILE *f_in, int *count);

tree_t *create_node(char *word, int h);

void free_tree(tree_t *tree);

int find_tree(tree_t *tree, char *word, int *count_cmp);


#endif // __TREE_DDP_H__
