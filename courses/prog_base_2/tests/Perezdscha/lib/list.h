#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define MIN_CAPACITY 2

typedef struct list_s * list_t;

list_t list_new();
void list_delete(list_t list);

void list_insert(list_t list, int element, int index);
void list_remove(list_t list, int index);

int list_get_element(list_t list, int index);
int list_get_size(list_t list);
int list_get_negcount(list_t list);
int list_get_poscount(list_t list);
int list_get_zerocount(list_t list);


#endif // LIST_H_INCLUDED
