#include <stdio.h>

#include "../inc/defs.h"
#include "../inc/tree.h"
#include "../inc/graphviz.h"
#include "../inc/read.h"
#include "../inc/utils.h"
#include "../inc/print_info.h"

int main(void)
{
    int key = -1;
    int rc;
    node_t *tree = NULL;
    char filename[MAX_STR_LEN + 1];

    printf("Программа для работы с бинарным деревом\n"
           "Шимшир Эмирджан ИУ7-33Б В-24\n"
           "\n"
           "(...)\n"
           "\n");

    print_menu();

    while (key != 0)
    {
        if (scanf("%d", &key) != 1)
        {
            printf("Ошибка ввода пункта меню\n");
            flush_input();
            continue;
        }

        switch (key)
        {
            case 1:
            {
                rc = fill_tree_from_file(&tree, filename);
                if (rc != 0)
                {
                    printf("Ошибка заполнения дерева данными из файла\n");
                    continue;
                }
                break;
            }
            case 2:
            {
                add_tree_word(&tree);
                break;
            }
            case 3:
            {
                print_tree(tree, 5);
                break;
            }
            case 4:
            {
                tree_export_to_dot(tree);
                break;
            }
        }

    }

    free_tree(tree);

    return 0;
}
