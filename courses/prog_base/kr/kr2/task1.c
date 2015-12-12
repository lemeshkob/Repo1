#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char * myStrchr(const char* str, int symbol);

char* myStrchr(const char* str, int symbol) {
    int i = 0;
    while (str[i] && str[i] != symbol) ++i;
    return symbol == str[i] ? (char*)str + i : NULL;
}

int main(void)
{
    const char * string={"Hello mu darling"};
    //puts("Enter your string here:\n");
   // gets(string);
    printf("Your string :\n%s",string);

    int symbol = 'l';
    puts("\nwe are looking for symbol 'l'");
      char * ach;
      ach = myStrchr(string, symbol);
      printf ("\nYour symbol is is on position # %d\n",ach-string+1);


}
