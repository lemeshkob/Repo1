#include "plural.h"

struct plural_s
{
    unsigned int arr[100];
    unsigned int count;
};

plural_t * plural_new(void)
{
    plural_t * s = malloc(sizeof(struct plural_s));
    s->count = 0;
    return s;
}

void plural_free(plural_t * self)
{
    free(self);
}

void plural_addEl(plural_t * self, int elem)
{
    if(self->count<100)
    {
        self->arr[self->count]=elem;
        self->count++;
    }
    else
        printf("Plural is full");
}

void plural_add_interval(plural_t * self,int first,int second)
{
    int i,j=0;
    if(self->count+(second-first+1)<=100)
    {
        for(i=self->count; i<self->count+abs(second-first)+1; i++)
        {
            self->arr[i]=first+j;
            j++;
        }
        self->count+=abs(second-first)+1;
    }
    else
        printf("too long interval\n");
}

void plural_put(plural_t * self)
{
    int i;
    for(i=0; i<self->count; i++)
    {
        printf("%i ",self->arr[i]);
    }
    printf("\n\n");
}

void plural_random(plural_t * self)
{
    int i;
    self->count=rand()%10+1;
    for(i=0; i<self->count; i++)
        self->arr[i]=rand()%1000+1;
}

plural_t* plural_merger(plural_t * p1, plural_t * p2)
{
    int i,j,chek,save;
    save=p1->count;
    for(i=0; i<p2->count; i++)
    {
        chek=0;
        for(j=0; j<p1->count; j++)
            if(p2->arr[i]==p1->arr[j])
                chek=1;
        if(chek==0)
        {
            if(p1->count+1>100)
            {
                printf("Merger array is too long");
                p1->count=0;
                return p1;
            }
            else
            {
                p1->arr[p1->count]=p2->arr[i];
                p1->count++;
            }
        }
    }
    return p1;
}

plural_t* plural_intersection(plural_t * p1, plural_t * p2)
{
    int i,j,chek,save;
    plural_t * result_plural=malloc(sizeof(plural_t));
    save=p1->count;
    for(i=0; i<p2->count; i++)
    {
        chek=0;
        for(j=0; j<p1->count; j++)
            if(p2->arr[i]==p1->arr[j])
                chek=1;
        if(chek==1)
        {
            result_plural->arr[result_plural->count]=p2->arr[i];
            result_plural->count++;
        }
    }
    return result_plural;
}

plural_t* plural_symdif(plural_t * p1, plural_t * p2)
{
    plural_t* result=malloc(sizeof(plural_t));
    int i,j,chek,fir=0;
    for(i=0; i<p1->count; i++)
    {
        chek=0;
        for(j=0; j<p2->count; j++)
            if(p1->arr[i]==p2->arr[j])
                chek=1;
            else
            {
                if(fir==0)
                {
                    result->arr[result->count]=p2->arr[j];
                    result->count++;
                }
            }
        if(0==chek)
        {
            result->arr[result->count]=p1->arr[i];
            result->count++;
        }
        fir=1;
    }
    return result;
}
