#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

int func(char * str, char * subStr);

static void subStr_count_zero(void ** state){
    char * str = "hello";
    char * substr = "by";
    assert_int_equal(func(str,substr), 0);
}

static void subStr_count_5(void ** state){
    char * str = "hellololololo";
    char * substr = "lo";
    assert_int_equal(func(str,substr), 5);
}

int func(char * str, char * subStr)
{
    char * p;
    int c = 0;
    p = strstr(str, subStr);
    while(p != NULL){
        c++;
        p = strstr((p + strlen(subStr)), subStr);
    }
    return c;
}



int main(void)
{
         const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(subStr_count_zero),
        cmocka_unit_test(subStr_count_5),

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
