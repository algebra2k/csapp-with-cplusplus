#include <cassert>
#include <limits>
#include <cstdio>

int int_shifts_are_arithmetic()
{
    int min = 0xffffffff;
    // shift left one and xor
    return !(min ^ (min >> 1));
}


void test_int_shifts_are_arithmetic()
{
    int8_t x = 0xff;
    int shift_val = sizeof(int8_t) - 1;
    x = x >> shift_val;
    if (x == -1) {
        assert(int_shifts_are_arithmetic() == 1);
        return;
    }

    if (x == 0) {
        assert(int_shifts_are_arithmetic() == 0);
        return;
    }

    printf("test int_shifts_are_arithmetic failed!\n");
    exit(1);
}

int main()
{
    test_int_shifts_are_arithmetic();
}