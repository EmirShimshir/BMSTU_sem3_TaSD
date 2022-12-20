#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "../inc/task.h"
#include "../inc/graph.h"
#include "../inc/io.h"
#include "../inc/errors.h"

int find_dst_with_Dijkstra(matrix_t *graph)
{
    if (check_graph_null(graph))
        return GRAPH_ERR;

    int top = 0;
    int max_way = 0;
    if (get_top_and_way(&top, &max_way, graph))
        return INPUT_ERR;

    int distance[graph->count];
    Dijkstra(graph, distance, top);

    printf("Плюсом будут выделены вершины,\n"
           "расстояние до которых от заданной \n"
           "меньше, чем указанное\n\n");

    to_dot(graph);

    FILE *f = fopen("data/task.gv", "w");
    fprintf(f, "digraph LAB_08 {\n");

    for (int i = 0; i < graph->count; ++i)
        for (int j = 0; j < graph->count; ++j)
            if (graph->data[i][j] != 0.)
                fprintf(f, "%d -> %d [label=\"%.1d\"];\n", i, j, graph->data[i][j]);

    for (int i = 0; i < graph->count; i++)
        if (distance[i] != INT_MAX && i != top)
        {
            if (distance[i] <= max_way)
            {
                fprintf(f, "%d -> %d [label=\"%d\" color=\"#228b22\" fontcolor=\"#228b22\"];\n", top, i, distance[i]);
                printf("+: %d -> %d = %d \n", top, i, distance[i]);
            }
            else
                printf("-: %d -> %d = %d \n", top, i, distance[i]);
        }
    fprintf(f, "}\n");
    fclose(f);

    system("dot -Tpng ./data/task.gv -otask.png");

    return EXIT_SUCCESS;

}

void Dijkstra(matrix_t *graph, int distance[graph->count], int top)
{
    int visited[graph->count];
    int buf = 0;

    for (int i = 0; i < graph->count; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[top] = 0;
    for (int count = 0; count < graph->count - 1; count++)
    {
        int min = INT_MAX;
        for (int i = 0; i < graph->count; i++)
        {
            if (visited[i] == 0 && distance[i] <= min)
            {
                min = distance[i];
                buf = i;
            }
        }

        visited[buf] = 1;
        for (int i = 0; i < graph->count; i++)
        {
            if (visited[i] == 0 && graph->data[buf][i] && distance[buf] != INT_MAX &&
                distance[buf] + graph->data[buf][i] < distance[i])
                distance[i] = distance[buf] + graph->data[buf][i];
        }
    }
}

int get_top_and_way(int *top, int *min_way, matrix_t *graph)
{
    printf("\nВведите ключевую вершину (номер): ");
    if (scanf("%d", top) != 1 || *top < 0 || *top > graph->count)
    {
        printf("Ошибка, неверный номер\n");
        return INPUT_ERR;
    }

    printf("\nВведите максимальную длину пути: ");
    if (scanf("%d", min_way) != 0 && *min_way < 0)
    {
        printf("Ошибка, число должно быть неотрицательным\n");
        return GRAPH_ERR;
    }

    return EXIT_SUCCESS;
}

void time_get()
{
    FILE *f1 = fopen("data/in_10.txt", "r");
    if (f1)
    {
        FILE *f2 = fopen("data/in_50.txt", "r");
        if (f2)
        {
            FILE *f3 = fopen("data/in_100.txt", "r");
            if (f3)
            {
                FILE *f4 = fopen("data/in_500.txt", "r");
                if (f4)
                {
                    printf("\nПроизводится сравнение времени работы и памяти, \n"
                           "затраченной на работу, алгоритма Дейкстры\n"
                           "Время в тиках, память в байтах:\n");
                    printf("| Кол-во |  Время  |  Память  |\n");
                    clock_t start, end;

                    matrix_t *g4 = read_matrix(f4);
                    int arr4[g4->count];
                    start = clock();
                    Dijkstra(g4, arr4, 0);
                    end = clock();
                    printf("| %6d |  %5lu  |  %7zu |\n", 500, end - start, sizeof(double)*g4->count + sizeof(matrix_t*));

                    matrix_t *g3 = read_matrix(f3);
                    int arr3[g3->count];
                    start = clock();
                    Dijkstra(g3, arr3, 0);
                    end = clock();
                    printf("| %6d |  %5lu  |  %7zu |\n", 100, end - start, sizeof(double)*g3->count + sizeof(matrix_t*));

                    matrix_t *g2 = read_matrix(f2);
                    int arr2[g2->count];
                    start = clock();
                    Dijkstra(g2, arr2, 0);
                    end = clock();
                    printf("| %6d |  %5lu  |  %7zu |\n", 50, end - start, sizeof(double)*g2->count + sizeof(matrix_t*));

                    matrix_t *g1 = read_matrix(f1);
                    int arr1[g1->count];
                    start = clock();
                    Dijkstra(g1, arr1, 0);
                    end = clock();
                    printf("| %6d |  %5lu  |  %7zu |\n", 10, end - start, sizeof(double)*g1->count + sizeof(matrix_t*));

                    fclose(f4);
                }
                fclose(f3);
            }
            fclose(f2);
        }
        fclose(f1);
    }
}