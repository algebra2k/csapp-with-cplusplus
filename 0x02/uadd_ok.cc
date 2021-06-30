#include <iostream>
#include <cassert>
#include <climits>
#include <cstdio>

inline bool uadd_ok(unsigned x, unsigned y)  {
    return static_cast<int>(x + y) < x? false : true;
}

void test_uadd_ok() {
    assert(uadd_ok(UINT_MAX, 1) == false);
    assert(uadd_ok(UINT16_MAX, UINT16_MAX) == true);
}

int main() {
    test_uadd_ok();

    return 0;
}