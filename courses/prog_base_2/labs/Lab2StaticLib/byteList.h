#ifndef BYTE_LIST_H
#define BYTE_LIST_H

#define MAXSIZE 10

typedef struct byteList_s  byteList_t;


 byteList_t *  byteList_new(void);
void  byteList_free( byteList_t * list);
void  byteList_add( byteList_t * list, int value);
int byteList_getSize(byteList_t * list);
int byteList_getData(byteList_t * list, int index);


#endif // BYTE_LIST_H
