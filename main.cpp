
#include <iostream>
#include <cmath>


float test_sin(float val)
{
    return sin(val);
}


size_t TEST_COUNT = 20;

int main(int argc, char *argv[])
{
    float valf = 0.25;
    for (size_t i = 0; i < TEST_COUNT; i++)
    {
        valf = test_sin(valf);
        printf("%2d: %X\n", i, *(int32_t*)&valf);
    }
}