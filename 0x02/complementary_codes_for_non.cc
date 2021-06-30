#include <iostream>
#include <cstdio>
int get_non(int x) {
    if (x == std::numeric_limits<int>::min()) {
        return x;
    }

    return -x;
}

int main() {

    assert(get_non(std::numeric_limits<int>::min()) == std::numeric_limits<int>::min());
    assert(get_non(std::numeric_limits<int>::min() + 1) == (-std::numeric_limits<int>::min() -1));

    return 0;
}


