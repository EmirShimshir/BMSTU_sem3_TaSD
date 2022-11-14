#include <stdio.h>
#include <stdlib.h>

#include "../inc/graphviz.h"

void tree_apply_pre(node_t *tree, ptr_action_t f, void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    tree_apply_pre(tree->left, f, arg);
    tree_apply_pre(tree->right, f, arg);
}


void node_to_dot(node_t *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%s -> %s [label=\"L\"]\n", tree->word, tree->left->word);

    if (tree->right)
        fprintf(f, "%s -> %s [label=\"R\"]\n", tree->word, tree->right->word);
}


void tree_export_to_dot(node_t *tree)
{
    FILE *f;
    f = fopen("tree", "w");

    fprintf(f, "digraph tree {\n");

    tree_apply_pre(tree, node_to_dot, f);

    fprintf(f, "}\n");

    fclose(f);

    system("dot -Tpng tree -otree.png");
    system("rm tree");
    system("open tree.png");
}