#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"

char asciiMax(char * str, char symbol)
{
    if(*str == '\0')
    {
        return symbol;
    }
    else
    {
        if(symbol < (int)*str )
            symbol=*str;
        asciiMax(str+1,symbol);
    }
}

int main()
{
    char str[20]={"Putin Huylo"};
    printf("%s\n ", str);
    char symbol = str[0];
   symbol = asciiMax(str, symbol);
   printf("%c", symbol);
    return 0;
}
