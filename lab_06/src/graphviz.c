#include <stdio.h>
#include <stdlib.h>

#include "../inc/graphviz.h"

void tree_apply_graphviz_pre(node_t *tree, FILE *f)
{
    if (tree == NULL)
        return;

    node_to_dot(tree, f);
    tree_apply_graphviz_pre(tree->left, f);
    tree_apply_graphviz_pre(tree->right, f);
}


void node_to_dot(node_t *tree, FILE *f)
{
    if (tree->left)
        fprintf(f, "%s -> %s [label=\"L\"]\n", tree->word, tree->left->word);

    if (tree->right)
        fprintf(f, "%s -> %s [label=\"R\"]\n", tree->word, tree->right->word);
}


void tree_export_to_dot(node_t *tree)
{
    FILE *f = fopen("tree", "w");

    fprintf(f, "digraph tree {\n");

    printf("1");

    tree_apply_graphviz_pre(tree, f);

    printf("2");

    fprintf(f, "}\n");

    fclose(f);

    system("dot -Tpng tree -otree.png");
    system("rm tree");
    system("open tree.png");
}