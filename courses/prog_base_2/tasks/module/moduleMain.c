#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "plural.h"

int main(void)
{
    plural_t * pl1 = plural_new();
    plural_t * pl2=plural_new();
    plural_t * pl3=plural_new();
    srand(time(NULL));
    plural_random(pl1);
    plural_random(pl2);
    plural_put(pl1);
    plural_put(pl2);
    pl3=plural_symdif(pl1,pl2);
    plural_put(pl3);
    plural_free(pl1);
    plural_free(pl2);
    plural_free(pl3);
    return 0;
}
