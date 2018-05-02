#include <iostream>
#include <cmath>

int TEST_COUNT = 20;

int main(int argc, char *argv[])
{
    void test_normal(int count);
    test_normal(TEST_COUNT);

    printf("\n\n");

    void test_by_fix16(int count);
    test_by_fix16(TEST_COUNT);

}

void myprintf(int i, double valf)
{
    printf("%2d: %I64X %lf\n", i, *(int64_t*)&valf, valf);
}
