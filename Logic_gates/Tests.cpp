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

void test_rs_trigger()
{
    Scheme scheme;
    //elements
    user_input user_input_r;
    user_input user_input_s;
    user_output user_output_q;
    user_output user_output_nq;
    logic_and logic_and1;
    logic_and logic_and2;
    logic_not logic_not1;
    logic_not logic_not2;

    //connections
    logic_and1.in[0] = &user_input_r;
    logic_and1.in[1] = &logic_not2;
    logic_and2.in[0] = &logic_not1;
    logic_and2.in[1] = &user_input_s;
    logic_not1.in[0] = &logic_and1;
    logic_not2.in[0] = &logic_and2;
    user_output_q.in[0]  = &logic_not1;
    user_output_nq.in[0] = &logic_not2;

    scheme.add(static_cast<gate*>(&user_input_r));
    scheme.add(static_cast<gate*>(&user_input_s));
    scheme.add(static_cast<gate*>(&user_output_q));
    scheme.add(static_cast<gate*>(&user_output_nq));
    scheme.add(static_cast<gate*>(&logic_and1));
    scheme.add(static_cast<gate*>(&logic_and2));
    scheme.add(static_cast<gate*>(&logic_not1));
    scheme.add(static_cast<gate*>(&logic_not2));


    scheme.compile();
    scheme.dump();

    // test1 initial condition
    user_input_r.out = false;
    user_input_s.out = false;
    scheme.solve();
    assert(user_output_q.out  == true);
    assert(user_output_nq.out == true);

    // test2 nothing change (step from initial condition)
    user_input_r.out = false;
    user_input_s.out = false;
    scheme.solve();
    assert(user_output_q.out == true);
    assert(user_output_nq.out == true);

    // test3 set
    user_input_r.out = false;
    user_input_s.out = true;
    scheme.solve();
    assert(user_output_q.out == true);
    assert(user_output_nq.out == false);

    // test4 set hold
    user_input_r.out = false;
    user_input_s.out = true;
    scheme.solve();
    assert(user_output_q.out == true);
    assert(user_output_nq.out == false);

    // test5 set memory
    user_input_r.out = false;
    user_input_s.out = false;
    scheme.solve();
    assert(user_output_q.out == true);
    assert(user_output_nq.out == false);

    // test6 reset hold 
    user_input_r.out = true;
    user_input_s.out = false;
    scheme.solve();
    assert(user_output_q.out == false);
    assert(user_output_nq.out == true);

    // test7 reset memory 
    user_input_r.out = false;
    user_input_s.out = false;
    scheme.solve();
    assert(user_output_q.out == false);
    assert(user_output_nq.out == true);

    // test8 last nothing change
    user_input_r.out = false;
    user_input_s.out = false;
    scheme.solve();
    assert(user_output_q.out == false);
    assert(user_output_nq.out == true);
}


void test()
{
#if 0
    test_and();
    test_or();
    test_not();
    test_xor();
    
    //test_simle_scheme();
    //test_simle_scheme2();

    test_simple_ordered_scheme();
    test_simple_disordered_scheme();

#endif
    test_rs_trigger();
}
