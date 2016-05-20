#include "main.h"

int check_foo(byteList_t * list){
    int sum = 0;
    for(int i = 0; i<byteList_getSize(list); i++)
        sum+=byteList_getData(list, i);
    return sum;
}

void reaction(int check){
    if(check > 255)
        puts("\nOVERFLOW\n");
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
    switch (fdwReason){
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
