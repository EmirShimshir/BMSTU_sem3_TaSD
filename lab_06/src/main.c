#include <stdio.h>

#include "../inc/defs.h"
#include "../inc/tree.h"
#include "../inc/graphviz.h"
#include "../inc/read.h"
#include "../inc/utils.h"
#include "../inc/print_info.h"
#include "../inc/task.h"

int main(void)
{
    int key = -1;
    int rc;
    node_t *tree = NULL;

    printf("Программа для работы с бинарным деревом\n"
           "Шимшир Эмирджан ИУ7-33Б В-24\n"
           "\n"
           "(...)\n"
           "\n");

    print_menu();

    while (key != 0)
    {
        printf("Введите пункт меню: ");
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
                char filename[MAX_STR_LEN + 1];
                rc = fill_tree_from_file(&tree, filename);
                if (rc != 0)
                {
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
                if (tree == NULL)
                {
                    printf("Дерево пустое\n");
                    break;
                }
                print_tree(tree, 5);
                break;
            }
            case 4:
            {
                if (tree == NULL)
                {
                    printf("Дерево пустое\n");
                    break;
                }
                tree_export_to_dot(tree);
                break;
            }
            case 5:
            {
                if (tree == NULL)
                {
                    printf("Дерево пустое\n");
                    break;
                }
                print_all_words_by_first_letter(tree);
                break;
            }
            case 6:
            {
                if (tree == NULL)
                {
                    printf("Дерево пустое\n");
                    break;
                }
                delete_word(&tree);
                break;
            }
            case 7:
            {
                if (tree != NULL)
                {
                    free_tree(tree);
                    tree = NULL;
                }
                rc = delete_by_first_letter_compare(&tree);
                if (rc != 0)
                {
                    continue;
                }
                break;
            }
        }

    }

    free_tree(tree);

    return 0;
}
