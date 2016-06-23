#include "main.h"

struct soc_net_s  {
    char * name;
    int cur_clients;
    char * info;
};

soc_net_t * DLL_EXPORT soc_net_new(char * name, char * info)
{
    soc_net_t * self = NULL;
    self =  malloc(sizeof(struct soc_net_s));
    self->name = malloc(sizeof(char) * strlen(name));
    strcpy(self->name, name);
    self->info = malloc(sizeof(char) * strlen(name));
    strcpy(self->info, info);
    self->cur_clients = 0;
    return self;
}

void DLL_EXPORT soc_net_free(soc_net_t *self)
{
    free(self);
}
void DLL_EXPORT soc_net_add_client(soc_net_t * self)
{
    self->cur_clients++;
}

void DLL_EXPORT soc_net_del_client(soc_net_t * self)
{
    if (self->cur_clients > 0)
        self->cur_clients--;
}

int DLL_EXPORT soc_net_cur_clients(soc_net_t * self)
{
    return self->cur_clients;
}

char * DLL_EXPORT soc_net_name(soc_net_t * self)
{
    return self->name;
}

soc_net_t * DLL_EXPORT soc_net_most_popular(soc_net_t ** self, int size)
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


extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
