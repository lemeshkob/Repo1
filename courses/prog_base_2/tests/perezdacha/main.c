#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int func(char * str, char * substr){
    int c = 0;
    int length = 0;
    length  = strlen(str);
    char * p = strstr(str, substr);
    printf("%s\n", p);
    while (p){
        c++;
        p = strstr(str, substr);
        str = str + length/sizeof(char);
    }
    return c;
}



int main(void){

    int ret = func("hehehehelphellhellohehehe", "l");
    printf("%i", ret);
    return 0;
}
