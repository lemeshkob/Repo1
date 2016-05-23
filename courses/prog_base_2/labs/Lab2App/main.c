#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "byteList.h"

typedef int (*check_f)(byteList_t * list);
typedef void (*react_f)(int check);

typedef struct dynamic_s
{
    HANDLE hLib;
    check_f check;
    react_f react;
} dynamic_t;

dynamic_t * dynamic_newDyn(const char * dllName);
void dynamic_freeDyn(dynamic_t * dyn);

const char * userChoice();
void printList(byteList_t * list);

int main()
{
    srand(time(NULL));
   byteList_t * list = newList();
    const char * dllName = userChoice();
    dynamic_t * dll = dynamic_newDyn(dllName);
    if(dll == NULL)
    {
        puts("\nCan't load library!");
        byteList_free(list);
        return 1;
    } else if(dll->check == NULL)
    {
        puts("\nCan't load check function!");
        byteList_free(list);
        return 1;
    } else if(dll->react == NULL)
    {
        puts("\nCant load react function!");
        byteList_free(list);
        return 1;
    }
    puts("\nDLL loaded!");
    Sleep(650);
    while(byteList_getSize(list) < MAXSIZE)
    {
        byteList_add(list, rand() % 256 + (-127));
        //list_add(list, rand() % 50);
        byteList_printList(list);
        dll->react(dll->check(list));
        Sleep(750);
    }

    FreeLibrary(dll->hLib);
    byteList_free(list);
    return 0;
}

dynamic_t * dynamic_newDyn(const char * dllName)
{
    dynamic_t * dyn = malloc(sizeof(struct dynamic_s));
    dyn->hLib = LoadLibrary(dllName);
    dyn->check = NULL;
    dyn->react = NULL;
    if(dyn->hLib != NULL)
    {
        dyn->check = (check_f)GetProcAddress(dyn->hLib, "check_foo");
        dyn->react = (react_f)GetProcAddress(dyn->hLib, "reaction");
        return dyn;
    }else
    {
        return NULL;
    }

}

void printList(byteList_t * list)
{
    system("cls");
    byteList_printList(list);
    Sleep(750);
}

const char * userChoice()
{
    int dllNum = 0;
    while(dllNum < 1 || dllNum > 2)
    {
        printf("Chose dll to use(1 or 2):\n>> ");
        scanf("%i", &dllNum);
        if(dllNum == 1)
            return ("Lab2DLL1.dll");
        else if (dllNum == 2)
            return ("Lab2DLL2.dll");
    }
    return NULL;
}

void dynamic_freeDyn(dynamic_t * dyn)
{
    FreeLibrary(dyn->hLib);
    free(dyn);
}
