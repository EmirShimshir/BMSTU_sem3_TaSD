#include <stdio.h>
#include <string.h>
#include <time.h>

#include "read_cars.h"
#include "print_cars.h"
#include "errors.h"

int delete_record(car_table_t *table)
{
    printf("Введите цену машин (тыс руб), которые вы хотите удалить: ");

    unsigned int price;
    size_t count = 0;

    int exit_code = read_delete_price(&price);

    if (exit_code)
        return exit_code;

    for (size_t i = 0; i < table->len; i++)
    {
        if (table->table[i].price == price)
        {
            for (size_t j = i; j < table->len - 1; j++)
                table->table[j] = table->table[j + 1];
            table->len--;
            count++;
            i--;
        }
    }

    if (count == 0)
        return ERR_NO_CARS;

    puts("\nДанные успешно удалены!");

    return CARS_OK;
}

int find_records(car_table_t *table)
{
    int exit_code = CARS_OK;
    puts("Задайте параметры поиска.");

    printf("Марка: ");

    char brand[MAX_BRAND_LEN + 1];
    exit_code = read_find_brand(brand);

    if (exit_code)
        return exit_code;

    puts("Цена:");
    printf("от: ");

    unsigned int lower_price;
    exit_code = read_delete_price(&lower_price);

    if (exit_code)
        return exit_code;

    printf("до: ");
    unsigned int top_price;
    exit_code = read_delete_price(&top_price);

    if (exit_code)
        return exit_code;

    if (lower_price > top_price)
        return ERR_INCORRECT_PRICES;

    size_t count = 0;

    for (size_t i = 0; i < table->len; i++)
    {
        car_t record = table->table[i];
        if (record.condition == USED && 
            record.more_info.used_car.owners_num == 1 &&
            record.more_info.used_car.repairs_num == 0 &&
            !strcmp(brand, record.brand) && 
            record.price >= lower_price && 
            record.price <= top_price)
        {
            if (count == 0)
                print_header();
            
            count++;

            print_record(&record);
        }
    }

    if (count == 0)
        return ERR_NO_RECORDS;

    print_down_line();

    return CARS_OK;
}

void swap(void *first, void *second, size_t size)
{
    char *f = first;
    char *s = second;
    do
    {
        char tmp = *f;
        *f++ = *s;
        *s++ = tmp;
    } while (--size);
}

int compare_records(const void *first, const void *second)
{
    const car_t *f = first;
    const car_t *s = second;
    return f->price - s->price;
}

int compare_keys_records(const void *first, const void *second)
{
    const car_key_t *f = first;
    const car_key_t *s = second;
    return f->price - s->price;
}

void heapify(void *first, size_t number, size_t bottom, size_t size,
             int (* comparator) (const void *, const void *))
{
    size_t num = bottom - 1;
    size_t first_neighbour = 2 * num + 1;
    size_t second_neighbour = 2 * num + 2;
    size_t max_node;

    while (first_neighbour < number)
    {
        if (second_neighbour < number)
        {
            if ((*comparator)(first + first_neighbour * size, first + second_neighbour * size) > 0)
                max_node = first_neighbour;

            else
                max_node = second_neighbour;
        }
        else
            max_node = first_neighbour;

        if ((*comparator)(first + num * size, first + max_node * size) < 0)
        {
            swap(first + num * size, first + max_node * size, size);
            num = max_node;
            first_neighbour = 2 * num + 1;
            second_neighbour = 2 * num + 2;
        }
        else
            break;
    }
}

void build_heap(void *first, size_t number, size_t size, int (*comparator) (const void *, const void *))
{
    for (size_t i = number / 2; i > 0; i--)
        heapify(first, number, i, size, comparator);
}

void myheapsort(void *first, size_t number, size_t size, int (*comparator) (const void *, const void *))
{
    build_heap(first, number, size, comparator);
    size_t last = number - 1;

    for (size_t i = 0; i < number; i++)
    {
        swap(first, first + last * size, size);
        heapify(first, last, 1, size, comparator);
        last--;
    }
}

void insertionsort(void *first, size_t number, size_t size, int (*comparator) (const void *, const void *))
{
    for (size_t i = 1; i < number; i++)     
        for (int j = i; j > 0 && 
             (*comparator)(first + (j - 1) * size, first + j * size) > 0;j--)
                swap(first + (j - 1) * size, first + j * size, size);
}

void create_sort_keys_table(car_table_t *table, car_key_table_t *keys)
{
    create_keys_table(table, keys);

    myheapsort(&keys->table, keys->len, sizeof(car_key_t), &compare_keys_records);
}

void create_keys_table(car_table_t *table, car_key_table_t *keys)
{
    keys->len = table->len;

    for (size_t i = 0; i < table->len; i++)
    {
        keys->table[i].num = i;
        keys->table[i].price = table->table[i].price;
    }
}

void compare_heapsorts(car_table_t *table, car_key_table_t *keys)
{
    puts("\nСРАВНЕНИЕ ЭФФЕКТИВНОСТИ МЕТОДОВ\n");
    car_table_t sorted_table = *table;
    clock_t start, finish;

    puts("ПО ВРЕМЕНИ");

    start = clock();

    myheapsort(&sorted_table.table, sorted_table.len, sizeof(car_t), &compare_records);

    finish = clock();

    clock_t time = finish - start;

    printf("Время сортировки по исходной таблице: %ld msec\n", time);

    start = clock();

    myheapsort(&keys->table, keys->len, sizeof(car_key_t), &compare_keys_records);

    finish = clock();

    time = finish - start;

    printf("Время сортировки по таблице ключей: %ld msec\n", time);

    start = clock();

    create_keys_table(table, keys);
    
    finish = clock();

    time = finish - start;

    printf("Время выборки ключей из основной таблицы: %ld msec\n", time);

    puts("\nПО ПАМЯТИ");

    printf("Память, используемая при сортировке исходной таблицы: %ld байт\n",
           sizeof(car_t) * table->len);

    printf("Память, используемая при сортировке исходной таблицы: %ld байт\n\n",
           sizeof(car_t) * table->len + sizeof(car_key_t) * table->len);
}

void compare_sorts_types(car_table_t *table, car_key_table_t *keys)
{
    car_table_t sorted_table = *table;
    car_key_table_t sorted_keys = *keys;
    clock_t start, finish;

    puts("\nПИРАМИДАЛЬНАЯ СОРТИРОВКА");

    start = clock();

    myheapsort(&sorted_table.table, sorted_table.len, sizeof(car_t), &compare_records);

    finish = clock();

    clock_t time = finish - start;

    printf("Время сортировки по исходной таблице: %ld msec\n", time);

    start = clock();


    myheapsort(&sorted_keys.table, sorted_keys.len, sizeof(car_key_t), &compare_keys_records);

    finish = clock();

    time = finish - start;

    printf("Время сортировки по таблице ключей: %ld msec\n\n", time);

    sorted_table = *table;
    sorted_keys = *keys;

    puts("СОРТИРОВКА ВСТАВКАМИ");

    start = clock();

    insertionsort(&sorted_table.table, sorted_table.len, sizeof(car_t), &compare_records); 

    finish = clock();

    time = finish - start;

    printf("Время сортировки по исходной таблице: %ld msec\n", time);

    start = clock();

    insertionsort(&sorted_keys.table, sorted_keys.len, sizeof(car_key_t), &compare_keys_records);

    finish = clock();

    time = finish - start;

    printf("Время сортировки по таблице ключей: %ld msec\n\n", time);
}