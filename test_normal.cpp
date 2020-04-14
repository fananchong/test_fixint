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

extern float num2;

float test_normal_int_add(uint64_t count, float n)
{
    for (uint64_t i = 0; i < count; i++)
    {
        n += num2;
    }
    return n;
}

float test_normal_int_sub(uint64_t count, float n)
{
    for (uint64_t i = 0; i < count; i++)
    {
        n -= num2;
    }
    return n;
}

float test_normal_int_mul(uint64_t count, float n)
{
    for (uint64_t i = 0; i < count; i++)
    {
        n *= num2;
    }
    return n;
}

float test_normal_int_div(uint64_t count, float n)
{
    for (uint64_t i = 0; i < count; i++)
    {
        n /= num2;
    }
    return n;
}
