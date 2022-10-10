#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "picker.h"

#define MENU_BACK_TEXT "Back"
#define MENU_EXIT_TEXT "Exit"
#define ACTIVE_COLOR "\033[1;31m"

struct Menu
{
    struct MenuItemsList *items;
};

void execute_menu_item(menu_t menu, struct Node *node);

menu_t create_menu()
{
    menu_t menu = malloc(sizeof(struct Menu));

    menu->items = malloc(sizeof(struct MenuItemsList));
    init(menu->items);

    return menu;
}

void add_command(menu_t menu, void(*func)(void), const char *description)
{
    struct MenuItem item =
            {
                    .description = description,
                    .type = COMMAND_TYPE_ITEM,
                    .entity.func = func,
                    .is_active = DEFAULT_STATE
            };

    push(menu->items, &item);
}

void add_args_command(menu_t menu, void(*func)(void *), const char *description, void *packed_args)
{
    struct MenuItem item =
            {
                    .description = description,
                    .type = COMMAND_W_DATA_TYPE_ITEM,
                    .entity.func_w_data = func,
                    .is_active = DEFAULT_STATE,
                    .packed_args = packed_args
            };

    push(menu->items, &item);
}

void add_exit(menu_t menu, const char *description)
{
    struct MenuItem item =
            {
                    .description = description,
                    .type = EXIT_TYPE_ITEM,
                    .is_active = DEFAULT_STATE
            };

    push(menu->items, &item);
}

void add_sub_menu(menu_t menu, menu_t sub_menu, const char *description)
{
    struct MenuItem item =
            {
                    .description = description,
                    .type = MENU_TYPE_ITEM,
                    .entity.menu = sub_menu,
                    .is_active = DEFAULT_STATE
            };

    push(menu->items, &item);
    sub_menu->items->head->element->is_active = ACTIVE_STATE;
    add_exit(sub_menu, MENU_BACK_TEXT);
}

void print_menu(menu_t menu)
{
    struct Node *node = menu->items->head;

    set_cursor_to_start();

    while (node != NULL)
    {
        struct MenuItem *item = node->element;

        if (item->is_active == ACTIVE_STATE)
        {
            printf(ACTIVE_COLOR);
            printf("%s\n", item->description);
            printf("\033[0m");
        }
        else
        {
            printf("%s\n", item->description);
        }

        node = node->next;
    }
}

void print_back_menu()
{
    printf(ACTIVE_COLOR);
    printf("\n%s", MENU_BACK_TEXT);
    printf("\033[0m");
}

void select_next_item(menu_t menu, struct Node **node)
{
    (*node)->element->is_active = DEFAULT_STATE;

    if ((*node)->next != NULL)
    {
        (*node)->next->element->is_active = ACTIVE_STATE;
        *node = (*node)->next;
    }
    else
    {
        *node = menu->items->head;
        (*node)->element->is_active = ACTIVE_STATE;
    }
}


void select_prev_item(menu_t menu, struct Node **node)
{
    (*node)->element->is_active = DEFAULT_STATE;

    if ((*node)->prev != NULL)
    {
        (*node)->prev->element->is_active = ACTIVE_STATE;
        *node = (*node)->prev;
    }
    else
    {
        *node = menu->items->tail;
        (*node)->element->is_active = ACTIVE_STATE;
    }
}

void invoke_void_func(struct Node* node)
{
    node->element->entity.func();
}

void invoke_data_func(struct Node* node)
{
    node->element->entity.func_w_data(node->element->packed_args);
}

void execute_command(menu_t menu, struct Node *node, void(*invoke_func)(struct Node*))
{
    clear_console();
    invoke_func(node);
    print_back_menu();
    while (read_key() != ENTER_KEY);
    clear_console();
    print_menu(menu);

}

void menu_worker(menu_t menu)
{
    clear_console();

    struct Node *node = menu->items->head;
    while (node->element->is_active != ACTIVE_STATE)
        node = node->next;

    print_menu(menu);
    while (1)
    {
        print_menu(menu);

        key_e c = read_key();

        switch (c)
        {
            case DOWN_KEY:
                select_next_item(menu, &node);
                break;
            case UP_KEY:
                select_prev_item(menu, &node);
                break;
            default:
                switch (node->element->type)
                {
                    case COMMAND_TYPE_ITEM:
                        execute_command(menu, node, invoke_void_func);
                        break;
                    case COMMAND_W_DATA_TYPE_ITEM:
                        execute_command(menu, node, invoke_data_func);
                        break;
                    case MENU_TYPE_ITEM:
                        execute_menu_item(menu, node);
                        break;
                    default:
                        clear_console();
                        return;
                }
        }
    }
}

void execute_menu_item(menu_t menu, struct Node *node)
{
    clear_console();
    menu_worker(node->element->entity.menu);
    print_menu(menu);
}

void execute_menu(menu_t menu)
{
    add_exit(menu, MENU_EXIT_TEXT);
    struct Node *node = menu->items->head;
    node->element->is_active = ACTIVE_STATE;
    menu_worker(menu);
}

void free_menu(menu_t menu)
{
    struct Node *node = menu->items->head;

    while (node != NULL)
    {
        struct Node *next = node->next;

        if (node->element->type == MENU_TYPE_ITEM)
        {
            free_menu(node->element->entity.menu);
        }

        if (node->element->type == COMMAND_W_DATA_TYPE_ITEM)
        {
            free(node->element->packed_args);
        }

        free_node(node);
        node = next;
    }
    free(menu->items);
    free(menu);
}
