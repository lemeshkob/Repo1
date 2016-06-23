#include <stdio.h>
#include <stdlib.h>
#include "soc_net.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>


static void net_test1(void ** state)
{
    int size = 5;
    soc_net_t * net[size];
    net[0] = soc_net_new("VK", "info");
    net[1] = soc_net_new("Face", "info");
    net[2] = soc_net_new("Twit", "info");
    net[3] = soc_net_new("Inst", "info");
    net[4] = soc_net_new("Odnoklasnyky", "info");
    int count[5] = {6, 5, 8, 90, 7};
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < count[i]; j++)
            soc_net_add_client(net[i]);
    assert_int_equal(90, soc_net_cur_clients(soc_net_most_popular(net, size)));
}

static void net_test2(void ** state)
{
    int size = 5;
    soc_net_t * net[size];
    net[0] = soc_net_new("VK", "info");
    net[1] = soc_net_new("Face", "info");
    net[2] = soc_net_new("Twit", "info");
    net[3] = soc_net_new("Inst", "info");
    net[4] = soc_net_new("Odnoklasnyky", "info");
    int count[5] = {6, 5, 8, 90, 7};
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < count[i]; j++)
            soc_net_add_client(net[i]);
    assert_int_equal(90, soc_net_cur_clients(soc_net_most_popular(net, size)));
    assert_string_equal("Inst", soc_net_name(soc_net_most_popular(net, size)));
}

static void net_test3(void ** state)
{
    int size = 5;
    soc_net_t * net[size];
    net[0] = soc_net_new("VK", "info");
    net[1] = soc_net_new("Face", "info");
    net[2] = soc_net_new("Twit", "info");
    net[3] = soc_net_new("Inst", "info");
    net[4] = soc_net_new("Odnoklasnyky", "info");
    assert_int_equal(0, soc_net_cur_clients(soc_net_most_popular(net, size)));
    assert_string_equal("VK", soc_net_name(soc_net_most_popular(net, size)));
}

static void net_test4(void ** state)
{
    soc_net_t ** net = NULL;
    assert_null(soc_net_most_popular(net, 9));
}

int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(net_test1),
        cmocka_unit_test(net_test2),
        cmocka_unit_test(net_test3),
        cmocka_unit_test(net_test4),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

