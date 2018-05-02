
#include <iostream>
#include <cmath>


double test_sin(double val)
{
    return sin(val);
}


int TEST_COUNT = 20;

void myprintf(int i, double valf);
int main(int argc, char *argv[])
{
    double valf = 0.25;
    myprintf(-1, valf);
    for (int i = 0; i < TEST_COUNT; i++)
    {
        valf = test_sin(valf);
        myprintf(i, valf);
    }
}

void myprintf(int i, double valf)
{
    printf("%2d: %X\n", i, *(unsigned int*)&valf);
}
