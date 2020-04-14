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

extern float item;
Fix16 item_ = item;

float test_fix16_int_add(uint64_t count, float n)
{
    Fix16 n_ = n;
    for (uint64_t i = 0; i < count; i++)
    {
        n_ += item_;
    }
    return n_;
}

float test_fix16_int_sub(uint64_t count, float n)
{
    Fix16 n_ = n;
    for (uint64_t i = 0; i < count; i++)
    {
        n_ -= item_;
    }
    return n_;
}

float test_fix16_int_mul(uint64_t count, float n)
{
    Fix16 n_ = n;
    for (uint64_t i = 0; i < count; i++)
    {
        n_ *= item_;
    }
    return n_;
}

float test_fix16_int_div(uint64_t count, float n)
{
    Fix16 n_ = n;
    for (uint64_t i = 0; i < count; i++)
    {
        n_ /= item_;
    }
    return n_;
}
