#include "soc_net.h"
#include <string.h>
#include <stdlib.h>
struct soc_net_s {
    char * name;
    int cur_clients;
    char * info;
};

soc_net_t * soc_net_new(char * name, char * info)
{
    soc_net_t * self = malloc(sizeof(struct soc_net_s));
    self->name = malloc(sizeof(char) * strlen(name));
    strcpy(self->name, name);
    self->info = malloc(sizeof(char) * strlen(name));
    strcpy(self->info, info);
    self->cur_clients = 0;
    return self;
}

void soc_net_free(soc_net_t *self)
{
    free(self);
}
void soc_net_add_client(soc_net_t * self)
{
    self->cur_clients++;
}

void soc_net_del_client(soc_net_t * self)
{
    if (self->cur_clients > 0)
        self->cur_clients--;
}

int soc_net_cur_clients(soc_net_t * self)
{
    return self->cur_clients;
}

char * soc_net_name(soc_net_t * self)
{
    return self->name;
}

soc_net_t * soc_net_most_popular(soc_net_t ** self, int size)
{
    if (self == NULL)
        return NULL;
    int max = self[0]->cur_clients;
    soc_net_t * pop_net = self[0];
    for (int i = 0; i < size; i++)
        if (self[i]->cur_clients > max)
        {
            max = self[i]->cur_clients;
            pop_net = self[i];
        }
    return pop_net;
}
