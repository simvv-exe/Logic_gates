#include "Tests.h"
#include "Gates.h"
#include <cassert>

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

void test()
{
    test_and();
    test_or();
    test_not();
    test_xor();
}
