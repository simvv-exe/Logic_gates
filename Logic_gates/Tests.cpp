#include "Tests.h"
#include "Gates.h"
#include "Scheme.h"
#include <cassert>

#if 0
void test_and()
{
    logic_and land;

    land.in1 = false;
    land.in2 = false;
    land.solve();
    assert(land.out == false);

    land.in1 = false;
    land.in2 = true;
    land.solve();
    assert(land.out == false);

    land.in1 = true;
    land.in2 = false;
    land.solve();
    assert(land.out == false);

    land.in1 = true;
    land.in2 = true;
    land.solve();
    assert(land.out == true);
}

void test_or()
{
    logic_or lor;

    lor.in1 = false;
    lor.in2 = false;
    lor.solve();
    assert(lor.out == false);

    lor.in1 = false;
    lor.in2 = true;
    lor.solve();
    assert(lor.out == true);

    lor.in1 = true;
    lor.in2 = false;
    lor.solve();
    assert(lor.out == true);

    lor.in1 = true;
    lor.in2 = true;
    lor.solve();
    assert(lor.out == true);
}

void test_not()
{
    logic_not lnot;

    lnot.in = false;
    lnot.solve();
    assert(lnot.out == true);

    lnot.in = true;
    lnot.solve();
    assert(lnot.out == false);
}

void test_xor()
{
    logic_xor lxor;

    lxor.in1 = false;
    lxor.in2 = false;
    lxor.solve();
    assert(lxor.out == false);

    lxor.in1 = false;
    lxor.in2 = true;
    lxor.solve();
    assert(lxor.out == true);

    lxor.in1 = true;
    lxor.in2 = false;
    lxor.solve();
    assert(lxor.out == true);

    lxor.in1 = true;
    lxor.in2 = true;
    lxor.solve();
    assert(lxor.out == false);
}
#endif

#if 0
void test_simle_scheme()
{
    //elements
    user_input user_input1;
    logic_not logic_not1;
    user_output user_output1;

    //connections
    logic_not1.in = &user_input1;
    user_output1.terminal = &logic_not1;

    // test1
    user_input1.out = false;
    logic_not1.solve();
    assert(user_output1.get_rez() == true);

    // test2
    user_input1.out = true;
    logic_not1.solve();
    assert(user_output1.get_rez() == false);

    // test3
    user_input1.out = true;
    logic_not1.solve();
    assert(user_output1.get_rez() == false);
}

void test_simle_scheme2()
{
    //elements
    user_input user_input1;
    logic_not logic_not1;
    logic_not logic_not2;
    user_output user_output1;

    //connections
    logic_not1.in = &user_input1;
    logic_not2.in = &logic_not1;
    user_output1.terminal = &logic_not2;

    // test1
    user_input1.out = false;
    logic_not1.solve();
    logic_not2.solve();
    assert(user_output1.get_rez() == false);

    // test2
    user_input1.out = true;
    logic_not1.solve();
    logic_not2.solve();
    assert(user_output1.get_rez() == true);

    // test3
    user_input1.out = true;
    logic_not1.solve();
    logic_not2.solve();
    assert(user_output1.get_rez() == true);
}
#endif

void test_simple_ordered_scheme()
{
    Scheme scheme;
    //elements
    user_input user_input1;
    logic_not logic_not1;
    user_output user_output1;

    //connections
    logic_not1.in[0] = &user_input1;
    user_output1.in[0] = &logic_not1;

    scheme.add(static_cast<gate*>(&user_input1));
    scheme.add(static_cast<gate*>(&logic_not1));
    scheme.add(static_cast<gate*>(&user_output1));
    

    scheme.prepare();
    scheme.dump();

    // test1
    user_input1.out = false;
    scheme.solve();
    assert(user_output1.out == true);

    // test2
    user_input1.out = true;
    scheme.solve();
    assert(user_output1.out == false);

    // test3
    user_input1.out = true;
    scheme.solve();
    assert(user_output1.out == false);
}

void test_simple_disordered_scheme()
{
    Scheme scheme;
    //elements
    user_input user_input1;
    user_output user_output1;
    logic_not logic_not1;

    //connections
    logic_not1.in[0] = &user_input1;
    user_output1.in[0] = &logic_not1;

    scheme.add(static_cast<gate*>(&user_input1));
    scheme.add(static_cast<gate*>(&user_output1));
    scheme.add(static_cast<gate*>(&logic_not1));


    scheme.prepare();
    scheme.dump();

    // test1
    user_input1.out = false;
    scheme.solve();
    assert(user_output1.out == true);

    // test2
    user_input1.out = true;
    scheme.solve();
    assert(user_output1.out == false);

    // test3
    user_input1.out = true;
    scheme.solve();
    assert(user_output1.out == false);
}

void test()
{
    //test_and();
    //test_or();
    //test_not();
    //test_xor();
    
    //test_simle_scheme();
    //test_simle_scheme2();

    test_simple_ordered_scheme();
    test_simple_disordered_scheme();
}
