
#include <iostream>
#include <cmath>


float test_float(float val)
{
    float v1 = val * 2;
    float v2 = v1 / 3;
    float v3 = sin(v2);
    float v4 = sqrtf(v3);
    return v4;
}


size_t TEST_COUNT = 100;

int main(int argc, char *argv[])
{
    float valf = 0.25;
    for (size_t i = 0; i < TEST_COUNT; i++)
    {
        valf = test_float(valf);
    }
    std::cout << "valf = " << valf << std::endl;
}