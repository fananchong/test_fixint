#include <iostream>
#include <cmath>

int TEST_COUNT = 20;

int main(int argc, char *argv[])
{
    printf("直接使用double类型，做sin运算：\n");
    void test_normal(int count);
    test_normal(TEST_COUNT);

    printf("\n\n");

    printf("使用libfixmath的fix16类型，做sin运算：\n");
    void test_by_fix16(int count);
    test_by_fix16(TEST_COUNT);

}

void myprintf(int i, double valf)
{
    printf("%2d: %llX %lf\n", i, *(long long int*)&valf, valf);
}
