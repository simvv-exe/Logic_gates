#include "Tests.h"
#include "Gates.h"
#include "Scheme.h"
#include <cassert>

void test_and()
{
    Scheme scheme;
    //elements
    user_input user_input1;
    user_input user_input2;
    user_output user_output1;
    logic_and land;

    //connections
    land.in[0] = &user_input1;
    land.in[1] = &user_input2;
    user_output1.in[0] = &land;

    scheme.add(static_cast<gate*>(&user_input1));
    scheme.add(static_cast<gate*>(&user_input2));
    scheme.add(static_cast<gate*>(&land));
    scheme.add(static_cast<gate*>(&user_output1));

    scheme.compile();
    scheme.dump();


    user_input1.out = false;
    user_input2.out = false;
    scheme.solve();
    assert(user_output1.out == false);

    user_input1.out = false;
    user_input2.out = true;
    scheme.solve();
    assert(user_output1.out == false);

    user_input1.out = true;
    user_input2.out = false;
    scheme.solve();
    assert(user_output1.out == false);

    user_input1.out = true;
    user_input2.out = true;
    scheme.solve();
    assert(user_output1.out == true);
}

void test_or()
{
    Scheme scheme;
    //elements
    user_input user_input1;
    user_input user_input2;
    user_output user_output1;
    logic_or lor;

    //connections
    lor.in[0] = &user_input1;
    lor.in[1] = &user_input2;
    user_output1.in[0] = &lor;

    scheme.add(static_cast<gate*>(&user_input1));
    scheme.add(static_cast<gate*>(&user_input2));
    scheme.add(static_cast<gate*>(&lor));
    scheme.add(static_cast<gate*>(&user_output1));

    scheme.compile();
    scheme.dump();


    user_input1.out = false;
    user_input2.out = false;
    scheme.solve();
    assert(user_output1.out == false);

    user_input1.out = false;
    user_input2.out = true;
    scheme.solve();
    assert(user_output1.out == true);

    user_input1.out = true;
    user_input2.out = false;
    scheme.solve();
    assert(user_output1.out == true);

    user_input1.out = true;
    user_input2.out = true;
    scheme.solve();
    assert(user_output1.out == true);
}

void test_not()
{
    Scheme scheme;
    //elements
    user_input user_input1;
    user_output user_output1;
    logic_not lnot;

    //connections
    lnot.in[0] = &user_input1;
    user_output1.in[0] = &lnot;

    scheme.add(static_cast<gate*>(&user_input1));
    scheme.add(static_cast<gate*>(&lnot));
    scheme.add(static_cast<gate*>(&user_output1));

    scheme.compile();
    scheme.dump();


    user_input1.out = false;
    scheme.solve();
    assert(user_output1.out == true);

    user_input1.out = true;
    scheme.solve();
    assert(user_output1.out == false);
}

void test_xor()
{
    Scheme scheme;
    //elements
    user_input user_input1;
    user_input user_input2;
    user_output user_output1;
    logic_xor lxor;

    //connections
    lxor.in[0] = &user_input1;
    lxor.in[1] = &user_input2;
    user_output1.in[0] = &lxor;

    scheme.add(static_cast<gate*>(&user_input1));
    scheme.add(static_cast<gate*>(&user_input2));
    scheme.add(static_cast<gate*>(&lxor));
    scheme.add(static_cast<gate*>(&user_output1));

    scheme.compile();
    scheme.dump();


    user_input1.out = false;
    user_input2.out = false;
    scheme.solve();
    assert(user_output1.out == false);

    user_input1.out = false;
    user_input2.out = true;
    scheme.solve();
    assert(user_output1.out == true);

    user_input1.out = true;
    user_input2.out = false;
    scheme.solve();
    assert(user_output1.out == true);

    user_input1.out = true;
    user_input2.out = true;
    scheme.solve();
    assert(user_output1.out == false);
}

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
    

    scheme.compile();
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


    scheme.compile();
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

void test_disordered_scheme_2input()
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


    scheme.compile();
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
    test_and();
    test_or();
    test_not();
    test_xor();
    
    //test_simle_scheme();
    //test_simle_scheme2();

    test_simple_ordered_scheme();
    test_simple_disordered_scheme();

    test_disordered_scheme_2input();
}
