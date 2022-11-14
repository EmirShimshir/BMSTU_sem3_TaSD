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

void free_tree(node_t *tree);
node_t *tree_init_node(char *word, int height);
node_t *tree_insert_node(node_t *tree, char *word, int *height, int *comp);
void print_tree(node_t *tree, int place);

#endif // __TREE__