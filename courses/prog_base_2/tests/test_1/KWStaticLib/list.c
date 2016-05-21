#include <stdlib.h>
#include "list.h"

struct list_s
{
    int * array;
    int size;
    int capacity;
};

list_t list_new()
{
    int * array = (int *)malloc(MIN_CAPACITY * sizeof(int));
    list_t newstruct = (struct list_s*)malloc(sizeof(struct list_s));
    newstruct->array = array;
    newstruct->size = 0;
    newstruct->capacity = MIN_CAPACITY;
    return newstruct;
}

void list_delete(list_t list)
{
    free(list->array);
    free(list);
}

static void increase_capacity(list_t list)
{
    int new_capacity = 2 * list->capacity;
    int * new_array = (int *)realloc(list->array, new_capacity * sizeof(int));
    list->array = new_array;
    list->capacity = new_capacity;
}
static void shiftright(list_t list, int starting_index)
{
    if(list->size >= list->capacity)
        increase_capacity(list); // ERROR
    int end = list->size;
    for(int i = starting_index, temp = list->array[i]; i < end; i++)
    {
        int prevtemp = list->array[i + 1];
        list->array[i + 1] = temp;
        temp = prevtemp;
    }
}
static void shiftleft(list_t list, int starting_index)
{
    int end = list->size - 1;
    for(int i = starting_index; i < end; i++)
        list->array[i] = list->array[i + 1];
}


//moves the value next
void list_insert(list_t list, int element, int index)
{
    if(index > list->size || index < 0)
        return; // ERROR
    shiftright(list, index);
    list->array[index] = element;
    list->size++;
}

void list_remove(list_t list, int index)
{
    if(index < 0 || index >= list->size)
        return; // ERROR
    shiftleft(list, index);
    list->size--;
}

int list_get_size(list_t list)
{
    return list->size;
}

int list_get_negcount(list_t list)
{
    int count = 0;
    int size = list->size;
    for(int i = 0; i < size; i++)
        if(list->array[i] < 0)
            count++;
    return count;
}
int list_get_poscount(list_t list)
{
    int count = 0;
    int size = list->size;
    for(int i = 0; i < size; i++)
        if(list->array[i] > 0)
            count++;
    return count;
}

int list_get_zerocount(list_t list)
{
    int count = 0;
    int size = list->size;
    for(int i = 0; i < size; i++)
        if(list->array[i] == 0)
            count++;
    return count;
}

int list_get_element(list_t list, int index)
{
    if(index >= list->size || index < 0)
        return;
    return list->array[index];
}
