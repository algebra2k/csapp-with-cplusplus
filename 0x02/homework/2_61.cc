#include <cstdio>
#include <limits>
#include<cassert>

int check_x(int x)
{
    int a = !~x;
    int b = !x;
    int c = !~(x | ~0xff);
    int d = !(x & 0xff000000);
    return  a || b || c || d;
}

void test_check_x()
{
    assert(check_x(0x00000000) == 1);
    assert(check_x(0xffffffff) == 1);
    assert(check_x(0x123456ff) == 1);
    assert(check_x(0x1234ffff) == 1);
    assert(check_x(0x12ffffff) == 1);
    assert(check_x(0x00abcdef) == 1);
    assert(check_x(0x0000cdef) == 1);
    assert(check_x(0x000000ef) == 1);
    assert(check_x(0x12345678) == 0);
}

int main()
{
    test_check_x();
}