#ifndef __TASK_H__
#define __TASK_H__

#include "graph.h"

int find_tops_with_Dijkstra(matrix_t *graph, int *count);
void Dijkstra(matrix_t *graph, double distance[graph->count], int top);
int get_top_and_way(int *top, double *min_way, matrix_t *graph);
void time_get();

#endif // __TASK_H__
