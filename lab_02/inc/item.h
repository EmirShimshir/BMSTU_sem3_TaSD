#ifndef UNIVERSAL_MENU_ITEM_H
#define UNIVERSAL_MENU_ITEM_H

#include "menu.h"

enum MENU_ITEM_TYPE
{
    COMMAND_TYPE_ITEM,
    COMMAND_W_DATA_TYPE_ITEM,
    MENU_TYPE_ITEM,
    EXIT_TYPE_ITEM,
};

enum MENU_ITEM_STATE
{
    ACTIVE_STATE,
    DEFAULT_STATE,
};

struct MenuItem
{
    const char *description;
    enum MENU_ITEM_TYPE type;
    enum MENU_ITEM_STATE is_active;

    union
    {
        void (*func)(void);

        void (*func_w_data)(void *);

        struct Menu *menu;
    } entity;

    void *packed_args;
};
#endif //UNIVERSAL_MENU_ITEM_H
