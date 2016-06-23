#ifndef SOC_NET_H_INCLUDED
#define SOC_NET_H_INCLUDED

typedef struct soc_net_s soc_net_t;
soc_net_t * soc_net_most_popular(soc_net_t ** self, int size);
char * soc_net_name(soc_net_t * self);
int soc_net_cur_clients(soc_net_t * self);
void soc_net_del_client(soc_net_t * self);
soc_net_t * soc_net_new(char * name, char * info);
void soc_net_free(soc_net_t *self);
void soc_net_setUsers(soc_net_t * self, int users):

#endif // SOC_NET_H_INCLUDED
