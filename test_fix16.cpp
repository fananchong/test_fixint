#include <iostream>
#include <cmath>
#include <fix16.hpp>
#include <fix16.h>

void myprintf(int i, double valf);

Fix16 test_sin_by_fix16(Fix16 val)
{
    return val.sin();
}

void test_by_fix16(int count)
{
    Fix16 valf(double(0.25));
    myprintf(-1, valf);
    for (int i = 0; i < count; i++)
    {
        valf = test_sin_by_fix16(valf);
        myprintf(i, valf);
    }
}