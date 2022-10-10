#include <string.h>
#include <stdlib.h>
#include "items_list.h"

struct Node *init(struct MenuItemsList *items)
{
    items->head = NULL;
    items->tail = NULL;
    items->count = 0;
    return items->head;
}

struct Node *push(struct MenuItemsList *items, struct MenuItem *element)
{
    void *p = malloc(sizeof(struct MenuItem));

    if (p == NULL)
        return items->head;

    struct Node *node = malloc(sizeof(struct Node));

    memcpy(p, element, sizeof(struct MenuItem));

    node->element = p;
    node->next = NULL;
    node->prev = items->tail;
    if (node->prev != NULL)
        node->prev->next = node;
    if (items->head == NULL)
        items->head = node;
    items->tail = node;
    items->count++;

    return items->head;
}


void free_node(struct Node *node)
{
    free(node->element);
    free(node);
}

