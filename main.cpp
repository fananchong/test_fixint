
#include <iostream>
#include <cmath>


float test_sin(float val)
{
    return sin(val);
}


int TEST_COUNT = 20;

void myprintf(int i, float valf);
int main(int argc, char *argv[])
{
    float valf = 0.25f;
    myprintf(-1, valf);
    for (int i = 0; i < TEST_COUNT; i++)
    {
        valf = test_sin(valf);
        myprintf(i, valf);
    }
}

void myprintf(int i, float valf) 
{
    printf("%2d: %X\n", i, *(int32_t*)&valf);
}