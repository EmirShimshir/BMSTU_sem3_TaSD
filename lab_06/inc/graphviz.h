#ifndef __GRAPHVIZ__

#define __GRAPHVIZ__

#include "tree.h"

typedef void (*ptr_action_t)(struct node_t*, void*);

void tree_apply_pre(node_t *tree, ptr_action_t f, void *arg);
void node_to_dot(node_t *tree, void *param);
void tree_export_to_dot(node_t *tree);

#endif // __GRAPHVIZ__
