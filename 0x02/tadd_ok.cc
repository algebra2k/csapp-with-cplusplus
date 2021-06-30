#include <iostream>
#include <cassert>
#include <climits>
#include <cstdio>

inline bool tadd_ok(int32_t x, int32_t y)  {
    int32_t s = x + y;
    if (x > 0 && y > 0 && s <= 0) return false;
    if (x < 0 && y < 0 && s >= 0) return false;
    return true;
}

void test_tadd_ok() {
    int min = std::numeric_limits<int32_t>::min();
    int max = std::numeric_limits<int32_t>::max();
    assert(tadd_ok(min, min) == false);
    assert(tadd_ok(min, min) == false);
    assert(tadd_ok(min, max) == true);

}

int main() {
    test_tadd_ok();

    return 0;
}