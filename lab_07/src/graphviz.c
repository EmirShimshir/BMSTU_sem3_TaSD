#include <stdio.h>
#include <stdlib.h>

#include "../inc/graphviz.h"

static void tree_apply_graphviz_pre(tree_t *tree, FILE *f);
static void node_to_dot(tree_t *tree, FILE *f);

void tree_export_to_dot_ddp(tree_t *tree)
{
    FILE *f = fopen("tree_ddp", "w");

    fprintf(f, "digraph tree_ddp {\n");

    tree_apply_graphviz_pre(tree, f);

    fprintf(f, "}\n");

    fclose(f);

    system("dot -Tpng tree_ddp -otree_ddp.png");
    system("rm tree_ddp");
}

void tree_export_to_dot_avl(tree_t *tree)
{
    FILE *f = fopen("tree_avl", "w");

    fprintf(f, "digraph tree_avl {\n");

    tree_apply_graphviz_pre(tree, f);

    fprintf(f, "}\n");

    fclose(f);

    system("dot -Tpng tree_avl -otree_avl.png");
    system("rm tree_avl");
}

static void tree_apply_graphviz_pre(tree_t *tree, FILE *f)
{
    if (tree == NULL)
        return;

    node_to_dot(tree, f);
    tree_apply_graphviz_pre(tree->left, f);
    tree_apply_graphviz_pre(tree->right, f);
}

static void node_to_dot(tree_t *tree, FILE *f)
{
    if (tree->left)
        fprintf(f, "%s -> %s [label=\"L\"]\n", tree->word, tree->left->word);

    if (tree->right)
        fprintf(f, "%s -> %s [label=\"R\"]\n", tree->word, tree->right->word);
}
