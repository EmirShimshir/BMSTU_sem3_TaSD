#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_ELEMS_COUNT_IN 10000
#define MAX_ELEMS 1000

typedef struct arr_t
{ 
    int arr[MAX_ELEMS_COUNT_IN];
    int begin;
    int end;
    int size;
} arr_t;

typedef struct node_t
{
    int elem;

    struct node_t *next;
} node_t;

typedef struct list_t
{
    node_t *head;
    node_t *tail;

    int size;
} list_t;


typedef struct
{
    node_t *arr_clear[MAX_ELEMS_COUNT_IN];
    int len;
} arr_clear_t;

#endif