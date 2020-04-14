#include <iostream>
#include <cmath>
#include <sys/time.h> // linux only , TODO 只支持 linux
#include <fix16.hpp>
#include <fix16.h>

bool myprintf_on = true;
long long mstime(void);

void test()
{
    void test_normal(uint64_t count);
    void test_by_fix16(uint64_t count);

    uint64_t count = 20;
    printf("直接使用double类型，做sin运算：\n");
    test_normal(count);

    printf("\n\n");

    printf("使用libfixmath的fix16类型，做sin运算：\n");
    test_by_fix16(count);
}

void test2()
{
    float num1 = 1999.5f;
    float num2 = 1.1f;
    printf("num1:%f, num2:%f\n", num1, num2);

    float a1 = [](float n1, float n2) -> float { return n1 + n2; }(num1, num2);
    float a2 = [](float n1, float n2) -> float { return float(Fix16(n1) + Fix16(n2)); }(num1, num2);
    printf("add, a1=%llX(%f), a2=%llX(%f)\n", *(long long int *)&a1, a1, *(long long int *)&a2, a2);

    a1 = [](float n1, float n2) -> float { return n1 - n2; }(num1, num2);
    a2 = [](float n1, float n2) -> float { return float(Fix16(n1) - Fix16(n2)); }(num1, num2);
    printf("sub, a1=%llX(%f), a2=%llX(%f)\n", *(long long int *)&a1, a1, *(long long int *)&a2, a2);

    a1 = [](float n1, float n2) -> float { return n1 * n2; }(num1, num2);
    a2 = [](float n1, float n2) -> float { return float(Fix16(n1) * Fix16(n2)); }(num1, num2);
    printf("div, a1=%llX(%f), a2=%llX(%f)\n", *(long long int *)&a1, a1, *(long long int *)&a2, a2);

    a1 = [](float n1, float n2) -> float { return n1 / n2; }(num1, num2);
    a2 = [](float n1, float n2) -> float { return float(Fix16(n1) / Fix16(n2)); }(num1, num2);
    printf("mul, a1=%llX(%f), a2=%llX(%f)\n", *(long long int *)&a1, a1, *(long long int *)&a2, a2);
}

void benchmark(uint64_t count)
{
    typedef float f1(float n1, float n2);
    typedef float f2(float n1, float n2);
    struct _temp
    {
        const char *name;
        f1 *f1_;
        f2 *f2_;
    };

    _temp temp[] = {
        {"add", [](float n1, float n2) -> float { return n1 + n2; }, [](float n1, float n2) -> float { return Fix16(n1) + Fix16(n2); }},
        {"sub", [](float n1, float n2) -> float { return n1 - n2; }, [](float n1, float n2) -> float { return Fix16(n1) - Fix16(n2); }},
        {"mul", [](float n1, float n2) -> float { return n1 * n2; }, [](float n1, float n2) -> float { return Fix16(n1) * Fix16(n2); }},
        {"div", [](float n1, float n2) -> float { return n1 / n2; }, [](float n1, float n2) -> float { return Fix16(n1) / Fix16(n2); }},
        {"sin", [](float n1, float _) -> float { return sin(n1); }, [](float n1, float _) -> float { return Fix16(n1).sin(); }},
    };

    // 避免溢出导致基准测试不准确
    float testvalue[] = {1999.5f, 1.1f, 1.995f, 1100.3f, 2000.95f, 109.98f};

    for (size_t i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
    {
        auto t1 = mstime();
        for (size_t j = 0; j < count; j++)
        {
            auto index = j % 3;
            temp[i].f1_(testvalue[2 * index], testvalue[2 * index + 1]);
        }
        auto t2 = mstime();
        printf("normal %s\tcount: %llu\t\tcost:%d ms\t%d ns/op\n", temp[i].name, count, t2 - t1, (t2 - t1) * 1000 * 1000 / count);

        t1 = mstime();
        for (size_t j = 0; j < count; j++)
        {
            auto index = j % 3;
            temp[i].f2_(testvalue[2 * index], testvalue[2 * index + 1]);
        }
        t2 = mstime();
        printf("fix16 %s\tcount: %llu\t\tcost:%d ms\t%d ns/op\n", temp[i].name, count, t2 - t1, (t2 - t1) * 1000 * 1000 / count);
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
            test2();
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
        printf("%2d: %llX %f\n", i, *(long long int *)&valf, valf);
    }
}
