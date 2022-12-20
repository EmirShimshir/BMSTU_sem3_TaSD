#include <stdio.h>
#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/io.h"
#include "../inc/graph.h"

void welcome_print()
{
    printf("Выберите номер пункта меню:\n\n"
           "1) Загрузить граф из файла .data/graph.txt\n"
           "2) Ввести граф вручную\n"
           "3) Вывести граф в виде png картинки\n"
           "4) Вывести матрицу графа\n"
           "5) Найти вершины, путь до которых от заданной не длиннее А\n"
           "6) Вывести сравнительную характеристику времени и памяти\n"
           "0) Выход\n\n"
           "Введите команду: ");
}

int get_command(int *command)
{
    welcome_print();
    fflush(stdin);
    if (scanf("%d", command) != 1 || *command < 1 || *command > 6)
    {
        printf("Ошибка, неверная команда\n");
        return INPUT_ERR;
    }

    return EXIT_SUCCESS;
}

matrix_t *read_matrix(FILE *f)
{
    int count;
    if (fscanf(f, "%d", &count) != 1)
        return NULL;

    matrix_t *matrix = create_matrix(count);
    int num;

    for (int i = 0; i < count; ++i)
        for (int j = 0; j < count; ++j)
        {
            if (fscanf(f, "%d", &num) != 1 || num < 0)
            {
                printf("Ошибка, неверный элемент\n");
                return NULL;
            }

            matrix->data[i][j] = num;
        }

    return matrix;
}

void print_matrix(FILE *f, matrix_t *graph)
{
    if (check_graph_null(graph))
        return;

    for (int i = 0; i < graph->count; ++i)
        for (int j = 0; j < graph->count; ++j)
            fprintf(f, "%6d%c", graph->data[i][j], j < graph->count - 1 ? ' ' : '\n');
}

void to_dot(matrix_t *graph)
{
    FILE *f = fopen("data/graph.gv", "w");

    fprintf(f, "digraph LAB_08 {\n");

    for (int i = 0; i < graph->count; ++i)
        for (int j = 0; j < graph->count; ++j)
            if (graph->data[i][j] != 0.)
                fprintf(f, "%d -> %d [label=\"%.1d\"];\n", i, j, graph->data[i][j]);

    fprintf(f, "}\n");
    fclose(f);

    system("dot -Tpng ./data/graph.gv -ograph.png");
}