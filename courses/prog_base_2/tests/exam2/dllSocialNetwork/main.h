#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

typedef struct soc_net_s soc_net_t;
soc_net_t *  DLL_EXPORT soc_net_most_popular(soc_net_t ** self, int size);
char * DLL_EXPORT soc_net_name(soc_net_t * self);
int DLL_EXPORT soc_net_cur_clients(soc_net_t * self);
void DLL_EXPORT soc_net_del_client(soc_net_t * self);
soc_net_t * DLL_EXPORT soc_net_new(char * name, char * info);
void DLL_EXPORT soc_net_free(soc_net_t *self);



#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
