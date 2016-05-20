#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
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

#include "byteList.h"

int DLL_EXPORT check_foo(byteList_t * list);

void DLL_EXPORT reaction(int check);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
