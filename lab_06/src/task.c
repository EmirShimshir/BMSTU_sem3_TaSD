#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/task.h"
#include "../inc/read.h"
#include "../inc/time.h"

typedef void (*search_t)(node_t **curr, char *word, node_t **parent);

static void print_all_words_by_first_letter_search_in(struct node_t *tree, char *word);

void print_all_words_by_first_letter(node_t *tree)
{
    char word[MAX_STR_LEN + 1];
    printf("Введите букву: ");
    scanf("%s", word);

    print_all_words_by_first_letter_search_in(tree, word);
}

static void print_all_words_by_first_letter_search_in(struct node_t *tree, char *word)
{
    if (tree == NULL)
        return;

    print_all_words_by_first_letter_search_in(tree->left, word);
    if (tree->word[0] == word[0])
        printf("%s\n", tree->word);
    print_all_words_by_first_letter_search_in(tree->right, word);
}

static node_t *get_min_word(node_t *curr);
static void search_word(node_t **curr, char *word, node_t **parent);
static int delete_node(node_t **tree, char *word, search_t search);

void delete_word(node_t **tree)
{
    char word[MAX_STR_LEN + 1];
    printf("Введите слово: ");
    scanf("%s", word);

    int rc = delete_node(tree, word, search_word);
    if (rc != 0)
        printf("В бинарном дереве нет такого слова\n");
    else
        printf("Данные успешно удалены\n");

}

// Вспомогательная функция для поиска узла минимального значения в поддереве с корнем curr
static node_t *get_min_word(node_t *curr)
{
    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}

// функция для поиска в поддереве с корнем curr и установки его родителя
static void search_word(node_t **curr, char *word, node_t **parent)
{
    // обход дерева и поиск ключа
    while (*curr != NULL && (strcmp(word, (*curr)->word) != 0))
    {
        // обновить родителя до текущего узла
        *parent = *curr;

        // если заданный ключ меньше текущего узла, переходим в левое поддерево
        // иначе идем в правое поддерево
        int cmp = strcmp(word, (*curr)->word);
        if (cmp < 0)
           *curr = (*curr)->left;
        else
            *curr = (*curr)->right;
    }
}

/*
* Функция удаляет узел из дерева
*
* Принимает указатель на указатель на корень, слово и функцию для поиска
*/
static int delete_node(node_t **tree, char *word, search_t search)
{
    // указатель для хранения родителя текущего узла
    node_t *parent = NULL;

    // начинаем с корневого узла
    node_t *curr = *tree;

    // поиск ключа и установка его родительского указателя
    search(&curr, word, &parent);

    // возвращаем, если ключ не найден в дереве
    if (curr == NULL)
        return 1;

    // Случай 1: удаляемый узел не имеет дочерних элементов, т. е. является листовым узлом
    if ((curr->left == NULL) && (curr->right == NULL))
    {
        // если удаляемый узел не является корневым узлом, то устанавливаем его
        // родительский левый/правый дочерний элемент в null
        if (curr != *tree)
        {
            if (parent->left == curr)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        // если дерево имеет только корневой узел, устанавливаем его в null
        else
        {
            *tree = NULL;
        }

        // освобождаем память
        free(curr);        // или delete curr;
    }

    // Случай 2: удаляемый узел имеет двух потомков
    else if (curr->left && curr->right)
    {
        // найти его неупорядоченный узел-преемник
        node_t *successor = get_min_word(curr->right);

        // сохраняем последующее значение
        char word_tmp[MAX_STR_LEN + 1];
        strcpy(word_tmp, successor->word);

        // рекурсивно удаляем преемника. Обратите внимание, что преемник
        // будет иметь не более одного потомка (правого потомка)
        delete_node(tree, successor->word, search_word);

        // копируем значение преемника в текущий узел
        strcpy(curr->word, word_tmp);
    }
    // Случай 3: удаляемый узел имеет только одного потомка
    else
    {
        // выбираем дочерний узел
        node_t *child = (curr->left) ? curr->left: curr->right;

        // если удаляемый узел не является корневым узлом, устанавливаем его родителя
        // своему потомку
        if (curr != *tree)
        {
            if (curr == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        // если удаляемый узел является корневым узлом, то установить корень дочернему
        else
        {
            *tree = child;
        }

        // освобождаем память
        free(curr);
    }

    return 0;
}

static void search_letter(node_t **curr, char *word, node_t **parent);
static void delete_from_file(char *filename, char *word);

int delete_by_first_letter_compare(node_t **tree)
{
    char filename[MAX_STR_LEN + 1];
    int rc = fill_tree_from_file(tree, filename);
    if (rc != 0)
        return rc;

    char word[MAX_STR_LEN + 1];
    printf("Введите букву: ");
    scanf("%s", word);

    unsigned long long tree_time_beg, tree_time_end, tree_time_res;

    tree_time_beg = microseconds_now();
    while (delete_node(tree, word, search_letter) == 0);
    tree_time_end = microseconds_now();
    tree_time_res = tree_time_end - tree_time_beg;

    printf("Данные из бинарного дерева успешно удалены\n");
    printf("Время удаления (микросекунды): %llu\n", tree_time_res);
    printf("Размер узла бинарного дерева (байты): %zu\n", sizeof(node_t));

    unsigned long long file_time_beg, file_time_end, file_time_res;

    file_time_beg = microseconds_now();
    delete_from_file(filename, word);
    file_time_end = microseconds_now();
    file_time_res = file_time_end - file_time_beg;

    printf("Данные из файла успешно удалены\n");
    printf("Время удаления (микросекунды): %llu\n", file_time_res);

    return 0;
}

// функция для поиска в поддереве с корнем curr и установки его родителя
static void search_letter(node_t **curr, char *word, node_t **parent)
{
    // обход дерева и поиск ключа
    while (*curr != NULL && (word[0] != (*curr)->word[0]))
    {
        // обновить родителя до текущего узла
        *parent = *curr;

        // если заданный ключ меньше текущего узла, переходим в левое поддерево
        // иначе идем в правое поддерево
        if (word[0] < (*curr)->word[0])
            *curr = (*curr)->left;
        else
            *curr = (*curr)->right;
    }
}

static void delete_from_file(char *filename, char *word)
{
    int count = 0;
    FILE *f = NULL;
    f = fopen(filename, "r");
    char word_temp[MAX_STR_LEN + 1];
    while ((fscanf(f, "%s", word_temp)) != EOF)
        count++;
    fclose(f);

    char arr_words[count][MAX_STR_LEN + 1];

    f = fopen(filename, "r");
    int i = 0;
    while ((fscanf(f, "%s", word_temp)) != EOF)
        strcpy(arr_words[i++], word_temp);
    fclose(f);

    f = fopen(filename, "w");
    for (int i = 0; i < count; i++)
        if (arr_words[i][0] != word[0])
            fprintf(f, "%s\n", arr_words[i]);
    fclose(f);

}
