#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../inc/tree.h"

void free_tree(node_t *tree)
{
    if (tree)
    {
        free_tree(tree->left);
        free_tree(tree->right);
    }

    free(tree);
}

node_t *tree_init_node(char *word, int height)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        return NULL;

    strcpy(node->word, word);
    node->height = height;
    node->left = NULL;
    node->right = NULL;

    return node;
}

node_t *tree_insert_node(node_t *tree, char *word, int *height, int *comp)
{
    (*height)++;
    if (!tree)
    {
        tree = tree_init_node(word, *height);
    }
    else
    {
        (*comp)++;
        int cmp = strcmp(word, tree->word);
        if (cmp < 0)
        {
            tree->left = tree_insert_node(tree->left, word, height, comp);
        }
        else if (cmp > 0)
        {
            tree->right = tree_insert_node(tree->right, word, height, comp);
        }
    }

    return tree;
}

void print_tree(node_t *tree, int place)
{
    int space = 5;

    if (tree)
    {
        place += space;

        print_tree(tree->right, place);

        printf("\n");

        for (int i = space; i < place; i++)
        {
            printf(" ");
        }

        printf("{ %s }\n", tree->word);

        print_tree(tree->left, place);
    }
}
