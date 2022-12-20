#include <stdio.h>
#include <stdlib.h>

#include "../inc/errors.h"
#include "../inc/graph.h"
#include "../inc/io.h"
#include "../inc/task.h"

int main()
{
    FILE *f_in = NULL;
    matrix_t *graph = malloc(sizeof(matrix_t*));
    graph->data = NULL;
    graph->count = 0;
    int command = -1;

    printf("Программа для поиска вершин графа, к которым от\n"
           "начальной вершины можно добраться по пути не\n"
           "длиннее А.\n"

           "Шимшир Эмирджан ИУ7-33Б\n"
           "\n"
           "(При вводе необходимо вводить только целые числа)\n"
           "\n");

    while (command)
    {
        get_command(&command);
        switch (command)
        {
            case 1:
                free_matrix(graph->data, 0);
                graph = NULL;

                f_in = fopen("./data/graph.txt", "r");

                if (f_in == NULL)
                {
                    printf("Ошибка открытия файла\n");
                    break;
                }

                graph = read_matrix(f_in);
                print_matrix(stdout, graph);
                break;

            case 2:
                free_matrix(graph->data, 0);
                graph = NULL;
                printf("Введите количество вершин и матрицу смежности графа (0 - нет ребра): \n");
                graph = read_matrix(stdin);
                break;

            case 3:
                if (check_empty_matrix(graph))
                    break;
                to_dot(graph);
                break;

            case 4:
                if (check_empty_matrix(graph))
                    break;
                print_matrix(stdout, graph);
                break;

            case 5:
                if (check_empty_matrix(graph))
                    break;

                find_dst_with_Dijkstra(graph);
                break;

            case 6:
                time_get();
                break;

            default:
                break;
        }
    }

    free_matrix(graph->data, graph->count);

    return EXIT_SUCCESS;
}
