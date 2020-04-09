#include <iostream>
#include <cmath>
#include <cassert>
#include <sys/time.h> // linux only , TODO 只支持 linux

bool myprintf_on = true;
long long mstime(void);
void test_normal(uint64_t count);
void test_by_fix16(uint64_t count);
int test_normal_int(uint64_t count, int n);
int test_fix16_int(uint64_t count, int n_);
void test()
{
    uint64_t TEST_COUNT = 20;
    printf("直接使用double类型，做sin运算：\n");
    test_normal(TEST_COUNT);

    printf("\n\n");

    printf("使用libfixmath的fix16类型，做sin运算：\n");
    test_by_fix16(TEST_COUNT);

    assert(test_normal_int(TEST_COUNT, 1999) == test_fix16_int(TEST_COUNT, 1999));
}

void benchmark()
{
    myprintf_on = false;
    uint64_t TEST_COUNT = 10000000;

    auto t1 = mstime();
    test_normal(TEST_COUNT);
    auto t2 = mstime();
    printf("normal sin: count: %llu,\t\tcost:%d ms,\t%d ns/op\n", TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);

    t1 = mstime();
    test_by_fix16(TEST_COUNT);
    t2 = mstime();
    printf("fix16 sin: count: %llu,\t\tcost:%d ms,\t%d ns/op\n", TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);

    TEST_COUNT = 10000000;

    t1 = mstime();
    test_normal_int(TEST_COUNT, 1999);
    t2 = mstime();
    printf("normal add int: count: %llu,\tcost:%d ms,\t%d ns/op\n", TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);

    t1 = mstime();
    test_fix16_int(TEST_COUNT, 1999);
    t2 = mstime();
    printf("fix16 add int: count: %llu,\t\tcost:%d ms,\t%d ns/op\n", TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        test();
    }
    else
    {
        benchmark();
    }
}

long long mstime(void)
{
    struct timeval tv;
    long long t;
    gettimeofday(&tv, NULL);
    t = ((long long)tv.tv_sec) * 1000;
    t += tv.tv_usec / 1000;
    return t;
}

void myprintf(int i, double valf)
{
    if (myprintf_on)
    {
        printf("%2d: %llX %lf\n", i, *(long long int *)&valf, valf);
    }
}
