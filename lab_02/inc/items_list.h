#ifndef UNIVERSAL_MENU_ITEMS_LIST_H
#define UNIVERSAL_MENU_ITEMS_LIST_H

#include "menu.h"
#include "stdio.h"
#include "item.h"

struct Node;

struct Node
{
    struct MenuItem *element;
    struct Node *prev;
    struct Node *next;
};

struct MenuItemsList
{
    struct Node *head;
    struct Node *tail;
    size_t count;
};

struct Node *init(struct MenuItemsList *items);

struct Node *push(struct MenuItemsList *items, struct MenuItem *element);

void free_node(struct Node *node);

#endif //UNIVERSAL_MENU_ITEMS_LIST_H
