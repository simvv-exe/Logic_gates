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

void test_rs_trigger()
{
    Scheme scheme;
    //elements
    user_input in_r("in_r");
    user_input in_s("in_s");
    user_output out_q("out_q");
    user_output out_nq("out_nq");
    logic_and and1("and1");
    logic_and and2("and2");
    logic_not not1("not1");
    logic_not not2("not2");

    //connections
    and1.in[0] = &in_r;
    and1.in[1] = &not2;
    and2.in[0] = &not1;
    and2.in[1] = &in_s;
    not1.in[0] = &and1;
    not2.in[0] = &and2;
    out_q.in[0]  = &not1;
    out_nq.in[0] = &not2;

    scheme.add(static_cast<gate*>(&in_r));
    scheme.add(static_cast<gate*>(&in_s));
    scheme.add(static_cast<gate*>(&out_q));
    scheme.add(static_cast<gate*>(&out_nq));
    scheme.add(static_cast<gate*>(&and1));
    scheme.add(static_cast<gate*>(&and2));
    scheme.add(static_cast<gate*>(&not1));
    scheme.add(static_cast<gate*>(&not2));


    scheme.compile();
    scheme.dump();

    // test1 initial condition
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out  == true);
    assert(out_nq.out == true);

    // test2 nothing change (step from initial condition)
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == true);

    // test3 set
    in_r.out = false;
    in_s.out = true;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test4 set hold
    in_r.out = false;
    in_s.out = true;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test5 set memory
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == true);
    assert(out_nq.out == false);

    // test6 reset hold 
    in_r.out = true;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test7 reset memory 
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);

    // test8 last nothing change
    in_r.out = false;
    in_s.out = false;
    scheme.solve();
    assert(out_q.out == false);
    assert(out_nq.out == true);
}


void test()
{
    test_and();
    test_or();
    test_not();
    test_xor();

    test_simple_ordered_scheme();
    test_simple_disordered_scheme();

    //test_rs_trigger();
}
