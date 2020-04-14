#include <iostream>
#include <cmath>
#include <sys/time.h> // linux only , TODO 只支持 linux

bool myprintf_on = true;
long long mstime(void);
void test_normal(uint64_t count);
void test_by_fix16(uint64_t count);
float test_normal_int_add(uint64_t count, float n);
float test_normal_int_sub(uint64_t count, float n);
float test_normal_int_mul(uint64_t count, float n);
float test_normal_int_div(uint64_t count, float n);
float test_fix16_int_add(uint64_t count, float n);
float test_fix16_int_sub(uint64_t count, float n);
float test_fix16_int_mul(uint64_t count, float n);
float test_fix16_int_div(uint64_t count, float n);
void test()
{
    uint64_t TEST_COUNT = 20;
    printf("直接使用double类型，做sin运算：\n");
    test_normal(TEST_COUNT);

    printf("\n\n");

    printf("使用libfixmath的fix16类型，做sin运算：\n");
    test_by_fix16(TEST_COUNT);
}

float item = 1.1f;

void test2(uint64_t TEST_COUNT)
{
    float item1 = 1999.5f;

    printf("num1:%f, num2:%f\n", item1, item);

    auto a1 = test_normal_int_add(TEST_COUNT, item1);
    auto a2 = test_fix16_int_add(TEST_COUNT, item1);
    printf("add, a1=%f, a2=%f\n", a1, a2);

    a1 = test_normal_int_sub(TEST_COUNT, item1);
    a2 = test_fix16_int_sub(TEST_COUNT, item1);
    printf("sub, a1=%f, a2=%f\n", a1, a2);

    a1 = test_normal_int_div(TEST_COUNT, item1);
    a2 = test_fix16_int_div(TEST_COUNT, item1);
    printf("div, a1=%f, a2=%f\n", a1, a2);

    a1 = test_normal_int_mul(TEST_COUNT, item1);
    a2 = test_fix16_int_mul(TEST_COUNT, item1);
    printf("mul, a1=%f, a2=%f\n", a1, a2);
}

void benchmark(uint64_t TEST_COUNT)
{
    myprintf_on = false;

    auto t1 = mstime();
    test_normal(TEST_COUNT);
    auto t2 = mstime();
    printf("normal sin\tcount: %llu\t\tcost:%d ms\t%d ns/op\n", TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);

    t1 = mstime();
    test_by_fix16(TEST_COUNT);
    t2 = mstime();
    printf("fix16 sin\tcount: %llu\t\tcost:%d ms\t%d ns/op\n", TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);

    typedef float f1(uint64_t count, float n);
    typedef float f2(uint64_t count, float n);
    struct _temp
    {
        const char *name;
        f1 *f1_;
        f2 *f2_;
    };

    _temp temp[] = {
        {"add", test_normal_int_add, test_fix16_int_add},
        {"sub", test_normal_int_sub, test_fix16_int_sub},
        {"mul", test_normal_int_mul, test_fix16_int_mul},
        {"div", test_normal_int_div, test_fix16_int_div},
    };

    for (size_t i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
    {
        t1 = mstime();
        temp[i].f1_(TEST_COUNT, 1999.5f);
        t2 = mstime();
        printf("normal %s\tcount: %llu\t\tcost:%d ms\t%d ns/op\n", temp[i].name, TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);

        t1 = mstime();
        temp[i].f2_(TEST_COUNT, 1999.5f);
        t2 = mstime();
        printf("fix16 %s\tcount: %llu\t\tcost:%d ms\t%d ns/op\n", temp[i].name, TEST_COUNT, t2 - t1, (t2 - t1) * 1000 * 1000 / TEST_COUNT);
    }
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        test();
    }
    else
    {
        auto s = atoi(argv[1]);
        auto c = atoi(argv[2]);
        if (s == 1)
        {
            benchmark(c);
        }
        else
        {
            test2(c);
        }
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
