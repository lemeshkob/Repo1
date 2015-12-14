#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void fprocess(const char * pread, const char * pwrite)
{
    FILE *in = fopen(pread,"r");
    FILE *out = fopen(pwrite,"w");
    char str[100];
    int i,j;
    for(i = 0; i < 23; i++)
    {
        fgets(str,100,in);
        if(22==i)
        {
            for(j = 0; j < strlen(str); j++)
            {
                fprintf(out,"%i ", str[j]);
            }
        }

    }
}

int main()
{
    FILE *input = "In.txt";
    FILE *output = "out.txt";
    fprocess(input, output);
    return 0;
}
