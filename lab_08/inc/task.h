#ifndef __TASK_H__
#define __TASK_H__

#include "graph.h"

int find_dst_with_Dijkstra(matrix_t *graph);

/*
* Функция для вызова алгоритма Дейкстры
*
* Принимает матрицу, массив расстояний до вершин, начальная вершина
*/
void Dijkstra(matrix_t *graph, int distance[graph->count], int top);
int get_top_and_way(int *top, int *min_way, matrix_t *graph);
void time_get();

#endif // __TASK_H__
