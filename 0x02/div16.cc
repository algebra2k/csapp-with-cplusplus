#include <cstdio>
#include <cassert>

int32_t div16(int32_t x) {
    return (x < 0? (x + (1 << 4)) - 1: x) >> 4;
}

void test_div16() {
    assert(div16(32) == 2);
    assert(div16(-32) == -2);
}

int main() {
    test_div16();
    return 0;
}