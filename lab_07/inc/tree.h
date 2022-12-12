#ifndef __TREE_H__
#define __TREE_H__

typedef struct tree_t
{
    char *word;
    int height;
    struct tree_t *left;
    struct tree_t *right;
} tree_t;

#endif // __TREE_H__