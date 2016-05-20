#ifndef PLURAL_H_INCLUDED
#define PLURAL_H_INCLUDED
#include <time.h>

typedef struct plural_s plural_t;

plural_t * plural_new(void);
void plural_free(plural_t * self);

void plural_addEl(plural_t * self, int elem);
void plural_add_interval(plural_t * self,int first,int second);
void plural_put(plural_t * self);
void plural_random(plural_t * self);

plural_t* plural_merger(plural_t * p1, plural_t * p2);
plural_t* plural_intersection(plural_t * p1, plural_t * p2);

#endif
