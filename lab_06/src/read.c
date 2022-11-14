#include <stdio.h>

#include "../inc/read.h"
#include "../inc/defs.h"

int fill_tree_from_file(node_t **tree, char *filename)
{
    printf("Введите имя файла: ");
    scanf("%s", filename);

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Ошибка, неверено введено имя файла\n");
        return 2;
    }

    char word[MAX_STR_LEN + 1];
    while ((fscanf(f, "%s", word)) != EOF)
    {
        int height = -1;
        int comp = 0;

        *tree = tree_insert_node(*tree, word, &height, &comp);
    }

    fclose(f);

    printf("Данные из файла успешно загружены\n");

    return 0;
}

int add_tree_word(node_t **tree)
{
    char word[MAX_STR_LEN + 1];
    printf("Введите слово: ");
    scanf("%s", word);

    int height = -1;
    int comp = 0;

    *tree = tree_insert_node(*tree, word, &height, &comp);

    printf("Слово успешно добавлено: глубина = %d, количество сравнений = %d\n", height, comp);

    return 0;
}
