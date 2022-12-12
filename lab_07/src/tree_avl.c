#include <string.h>

#include "../inc/constants.h"
#include "../inc/tree_avl.h"

static tree_t *add_balance(char *word, tree_t *tree, int *h);

/*
* Функция балансирует дерево
*
* Принимает указатель на корень дерева
*/
static tree_t *balance(tree_t *tree);
static void set_height(tree_t *root);
static int balance_factor(tree_t *root);
static unsigned char height(tree_t *root);
static tree_t *rotate_left(tree_t *tree);
static tree_t *rotate_right(tree_t *tree);

int create_tree_avl(tree_t **root, FILE *f_in)
{
    char str[WORD_SIZE];
    int h = -1;

    while (fgets(str, WORD_SIZE, f_in) != NULL)
    {
        if (str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = '\0';

        h = -1;
        *root = add_balance(str, *root, &h);
    }

    return OK;
}

static tree_t *add_balance(char *word, tree_t *tree, int *h)
{
    (*h)++;

    if (tree == NULL)
    {
        tree = create_node(word, *h);
    }
    else if (strcmp(word, tree->word) < 0)
    {
        tree->left = add_balance(word, tree->left, h);
    }
    else if (strcmp(word, tree->word) > 0)
    {
        tree->right = add_balance(word, tree->right, h);
    }

    return balance(tree);
}

static tree_t *balance(tree_t *tree)
{
    set_height(tree);

    if (balance_factor(tree) == 2)
    {
        if (balance_factor(tree->right) < 0)
            tree->right = rotate_right(tree->right);
        return rotate_left(tree);
    }

    if (balance_factor(tree) == -2)
    {
        if (balance_factor(tree->left) > 0)
            tree->left = rotate_left(tree->left);

        return rotate_right(tree);
    }

    return tree;
}

static void set_height(tree_t *root)
{
    unsigned char hl = height(root->left);
    unsigned char hr = height(root->right);
    root->height = (hl > hr ? hl : hr) + 1;
}

static int balance_factor(tree_t *root)
{
    return height(root->right) - height(root->left);
}

static unsigned char height(tree_t *root)
{
    return root ? root->height : 0;
}

static tree_t *rotate_left(tree_t *tree)
{
    tree_t *node = tree->right;
    tree->right = node->left;
    node->left = tree;
    set_height(tree);
    set_height(node);

    return node;
}

static tree_t *rotate_right(tree_t *tree)
{
    tree_t *node = tree->left;
    tree->left = node->right;
    node->right = tree;
    set_height(tree);
    set_height(node);

    return node;
}
