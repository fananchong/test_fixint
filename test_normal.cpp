#include <iostream>
#include <cmath>

void myprintf(int i, double valf);

double test_sin(double val)
{
    return sin(val);
}

void test_normal(uint64_t count)
{
    double valf = 0.25;
    myprintf(-1, valf);
    for (uint64_t i = 0; i < count; i++)
    {
        valf = test_sin(valf);
        myprintf(i, valf);
    }
}
