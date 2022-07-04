#include "Tests.h"
#include "Gates.h"
#include "Scheme.h"
#include <cassert>

void test_and()
{
    Scheme scheme;
    //elements
    user_input in1("in1");
    user_input in2("in2");
    user_output out1("out1");
    logic_and and1("and1");

    //connections
    and1.in[0] = &in1;
    and1.in[1] = &in2;
    out1.in[0] = &and1;

    scheme.add(static_cast<gate*>(&in1));
    scheme.add(static_cast<gate*>(&in2));
    scheme.add(static_cast<gate*>(&and1));
    scheme.add(static_cast<gate*>(&out1));

    scheme.compile();
    scheme.dump();


    in1.out = false;
    in2.out = false;
    scheme.solve();
    assert(out1.out == false);

    in1.out = false;
    in2.out = true;
    scheme.solve();
    assert(out1.out == false);

    in1.out = true;
    in2.out = false;
    scheme.solve();
    assert(out1.out == false);

    in1.out = true;
    in2.out = true;
    scheme.solve();
    assert(out1.out == true);
}

void test_or()
{
    Scheme scheme;
    //elements
    user_input in1("in1");
    user_input in2("in2");
    user_output out1("out1");
    logic_or or1("or1");

    //connections
    or1.in[0] = &in1;
    or1.in[1] = &in2;
    out1.in[0] = &or1;

    scheme.add(static_cast<gate*>(&in1));
    scheme.add(static_cast<gate*>(&in2));
    scheme.add(static_cast<gate*>(&or1));
    scheme.add(static_cast<gate*>(&out1));

    scheme.compile();
    scheme.dump();


    in1.out = false;
    in2.out = false;
    scheme.solve();
    assert(out1.out == false);

    in1.out = false;
    in2.out = true;
    scheme.solve();
    assert(out1.out == true);

    in1.out = true;
    in2.out = false;
    scheme.solve();
    assert(out1.out == true);

    in1.out = true;
    in2.out = true;
    scheme.solve();
    assert(out1.out == true);
}

void test_not()
{
    Scheme scheme;
    //elements
    user_input in1("in1");
    user_output out1("out1");
    logic_not not1("not1");

    //connections
    not1.in[0] = &in1;
    out1.in[0] = &not1;

    scheme.add(static_cast<gate*>(&in1));
    scheme.add(static_cast<gate*>(&not1));
    scheme.add(static_cast<gate*>(&out1));

    scheme.compile();
    scheme.dump();


    in1.out = false;
    scheme.solve();
    assert(out1.out == true);

    in1.out = true;
    scheme.solve();
    assert(out1.out == false);
}

void test_xor()
{
    Scheme scheme;
    //elements
    user_input in1("in1");
    user_input in2("in2");
    user_output out1("out1");
    logic_xor xor1("xor1");

    //connections
    xor1.in[0] = &in1;
    xor1.in[1] = &in2;
    out1.in[0] = &xor1;

    scheme.add(static_cast<gate*>(&in1));
    scheme.add(static_cast<gate*>(&in2));
    scheme.add(static_cast<gate*>(&xor1));
    scheme.add(static_cast<gate*>(&out1));

    scheme.compile();
    scheme.dump();


    in1.out = false;
    in2.out = false;
    scheme.solve();
    assert(out1.out == false);

    in1.out = false;
    in2.out = true;
    scheme.solve();
    assert(out1.out == true);

    in1.out = true;
    in2.out = false;
    scheme.solve();
    assert(out1.out == true);

    in1.out = true;
    in2.out = true;
    scheme.solve();
    assert(out1.out == false);
}

void test_simple_ordered_scheme()
{
    Scheme scheme;
    //elements
    user_input in1("in1");
    logic_not not1("not1");
    user_output out1("out1");

    //connections
    not1.in[0] = &in1;
    out1.in[0] = &not1;

    scheme.add(static_cast<gate*>(&in1));
    scheme.add(static_cast<gate*>(&not1));
    scheme.add(static_cast<gate*>(&out1));
    

    scheme.compile();
    scheme.dump();

    // test1
    in1.out = false;
    scheme.solve();
    assert(out1.out == true);

    // test2
    in1.out = true;
    scheme.solve();
    assert(out1.out == false);

    // test3
    in1.out = true;
    scheme.solve();
    assert(out1.out == false);
}

void test_simple_disordered_scheme()
{
    Scheme scheme;
    //elements
    user_input in1("in1");
    user_output out1("out1");
    logic_not not1("not1");

    //connections
    not1.in[0] = &in1;
    out1.in[0] = &not1;

    scheme.add(static_cast<gate*>(&in1));
    scheme.add(static_cast<gate*>(&out1));
    scheme.add(static_cast<gate*>(&not1));


    scheme.compile();
    scheme.dump();

    // test1
    in1.out = false;
    scheme.solve();
    assert(out1.out == true);

    // test2
    in1.out = true;
    scheme.solve();
    assert(out1.out == false);

    // test3
    in1.out = true;
    scheme.solve();
    assert(out1.out == false);
}

void test_rs_trigger_on_or()
{
    Scheme scheme;
    //elements
    user_input in_r("in_r");
    user_input in_s("in_s");
    user_output out_q("out_q");
    user_output out_nq("out_nq");
    logic_or or1("or1");
    logic_or or2("or2");
    logic_not not1("not1");
    logic_not not2("not2");

    //connections
    or1.in[0] = &in_r;
    or1.in[1] = &not2;
    or2.in[0] = &not1;
    or2.in[1] = &in_s;
    not1.in[0] = &or1;
    not2.in[0] = &or2;
    out_q.in[0]  = &not1;
    out_nq.in[0] = &not2;

    scheme.add(static_cast<gate*>(&in_r));
    scheme.add(static_cast<gate*>(&in_s));
    scheme.add(static_cast<gate*>(&out_q));
    scheme.add(static_cast<gate*>(&out_nq));
    scheme.add(static_cast<gate*>(&or1));
    scheme.add(static_cast<gate*>(&or2));
    scheme.add(static_cast<gate*>(&not1));
    scheme.add(static_cast<gate*>(&not2));


    scheme.compile();
    scheme.dump();

    // test1 initial condition
    in_r.out = true;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out  == false);
    assert(out_nq.out == true);

    // test2 nothing change (step from initial condition)
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test3 set
    in_r.out = false;
    in_s.out = true;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test4 set hold
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test5 set memory
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test6 reset 
    in_r.out = true;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test7 reset hold 
    in_r.out = true;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test8 reset memory 
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test9 one tick set
    in_r.out = false;
    in_s.out = true;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test10 set memory
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test11 one tick reset
    in_r.out = true;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test12 reset memory
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    //consecutive
}

void test_bliker()
{
    Scheme scheme;
    //elements
    user_input in("in");
    user_output out("out");
    logic_or or1("or1");
    logic_not not1("not1");

    //connections
    or1.in[0] = &in;
    not1.in[0] = &or1;
    or1.in[1] = &not1;
    out.in[0] = &or1;

    scheme.add(static_cast<gate*>(&in));
    scheme.add(static_cast<gate*>(&out));
    scheme.add(static_cast<gate*>(&or1));
    scheme.add(static_cast<gate*>(&not1));


    scheme.compile();
    scheme.dump();

    // test1 initial condition
    in.out = false;
    scheme.solve();
    assert(out.out == true);

    // test2 blink 1
    scheme.solve();
    assert(out.out == false);

    // test3 blink 2
    scheme.solve();
    assert(out.out == true);

    // test4 blink 3
    scheme.solve();
    assert(out.out == false);

    // test5 blink 4
    scheme.solve();
    assert(out.out == true);

    // test6 blink stopped
    in.out = true;
    scheme.solve();
    assert(out.out == true);

    // test7 nothing happens
    scheme.solve();
    assert(out.out == true);

    // test8 blink restart
    in.out = false;
    scheme.solve();
    assert(out.out == false);

    // test9 blink 1 after restart
    scheme.solve();
    assert(out.out == true);

    // test10 blink 2 after restart
    scheme.solve();
    assert(out.out == false);
}


//test_always_true

void test()
{
    test_and();
    test_or();
    test_not();
    test_xor();

    test_simple_ordered_scheme();
    test_simple_disordered_scheme();

    //test_rs_trigger_on_or();

    test_bliker();
}
