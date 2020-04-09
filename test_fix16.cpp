#include <iostream>
#include <cmath>
#include <fix16.hpp>
#include <fix16.h>

void myprintf(int i, double valf);

Fix16 test_sin_by_fix16(Fix16 val)
{
    return val.sin();
}

void test_by_fix16(uint64_t count)
{
    Fix16 valf(double(0.25));
    myprintf(-1, valf);
    for (uint64_t i = 0; i < count; i++)
    {
        valf = test_sin_by_fix16(valf);
        myprintf(i, valf);
    }
}

Fix16 test_int_by_fix16(Fix16 n)
{
    return (n + n) / Fix16(1.5f);
}

int test_fix16_int(uint64_t count, int n_)
{
    Fix16 n = Fix16(n_);
    for (uint64_t i = 0; i < count; i++)
    {
        n = test_int_by_fix16(Fix16(n));
    }
    return n;
}