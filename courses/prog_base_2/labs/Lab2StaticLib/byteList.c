#include <stdio.h>
#include <stdlib.h>

#include "byteList.h"

struct byteList_s{
    int * arr;
    int size;
};

byteList_t * byte_list_new(void){
    byteList_t * list = malloc(sizeof(struct  byteList_s));
    list->arr = malloc(sizeof(int)* MAXSIZE);
    list->size = 0;
    return list;
}

void  byteList_free( byteList_t * list){
    free(list->arr);
    free(list);
}

void  byteList_add( byteList_t * list, int value){
    if(MAXSIZE == list->size || value > 127 || value < -128){
        puts("Sorry, you can`t do this!");
        return;
    }
    list->arr[list->size++] = value;
}

int byteList_deleteEl(byteList_t * list){
    if(0 == list->size){
        return 1;
    }
    return list->arr[--list->size];
}

void byteList_printList(byteList_t * list){

    puts("\nYour list:\n");

        for(int i = 0; i<list->size; i++){
            printf("%i\t", list->arr[i]);
        }
    puts(" ");
}

int byteList_getSize(byteList_t * list){
    return list->size;
}

int byteList_getData(byteList_t * list, int index){
    if(0 == list->size || index < 0 ||
       index >= list->size)
        return;
    return list->arr[index];
}
