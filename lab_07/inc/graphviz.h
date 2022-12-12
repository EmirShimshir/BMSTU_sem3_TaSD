#ifndef __GRAPHVIZ_H__

#define __GRAPHVIZ_H__

#include "tree.h"

typedef void (*ptr_action_t)(struct tree_t*, void*);

void tree_export_to_dot_ddp(tree_t *tree);
void tree_export_to_dot_avl(tree_t *tree);

#endif // __GRAPHVIZ_H__
