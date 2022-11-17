#ifndef __READ__

#define __READ__

#include "tree.h"

int fill_tree_from_file(node_t **tree, char *filename);
int add_tree_word(node_t **tree);

#endif // __READ__