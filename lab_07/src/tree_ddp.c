#include <stdlib.h>
#include <string.h>

#include "../inc/constants.h"
#include "../inc/tree_ddp.h"

/*
* Функция добавляет новый узел в дерево
*
* Принимает указатель на корень, слово, указатель на глубину
*/
static tree_t *add_node(char *word, tree_t *tree, int *h);

int create_tree(tree_t **root, FILE *f_in, int *count)
{
    *count = 0;
    int h = -1;
    char str[WORD_SIZE];

    while (fgets(str, WORD_SIZE, f_in) != NULL)
    {
        if (str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = '\0';

        h = -1;
        *root = add_node(str, *root, &h);
        (*count)++;
    }

    return OK;
}

tree_t *create_node(char *word, int h)
{
    tree_t *node = malloc(sizeof(tree_t));

    if (node)
    {
        node->height = h;
        node->left = NULL;
        node->right = NULL;
        node->word = malloc(sizeof(char *) * (strlen(word) + 1));
        strcpy(node->word, word);
    }

    return node;
}

int find_tree(tree_t *tree, char *word, int *count_cmp)
{
    while (tree != NULL)
    {
        (*count_cmp)++;
        if (strcmp(tree->word, word) == 0)
            return OK;

        if (strcmp(tree->word, word) > 0)
        {
            tree = tree->left;
        }
        else if (strcmp(tree->word, word) < 0)
        {
            tree = tree->right;
        }
    }

    return NOT_FOUND;
}

void free_tree(tree_t *tree)
{
    if(tree)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

static tree_t *add_node(char *word, tree_t *tree, int *h)
{
    (*h)++;

    if (tree == NULL)
    {
        return create_node(word, *h);
    }
    else if (strcmp(word, tree->word) < 0)
    {
        tree->left = add_node(word, tree->left, h);
    }
    else if (strcmp(word, tree->word) > 0)
    {
        tree->right = add_node(word, tree->right, h);
    }

    return tree;
}
