#include <iostream>

int umul(uint32_t x, uint32_t y) {
    return (x % (std::numeric_limits<uint32_t>::max() + 1)) * (y % (std::numeric_limits<uint32_t>::max() + 1));
    // return (x * y) % (std::numeric_limits<uint32_t>::max() + 1);
}

int main() {
    uint32_t max = std::numeric_limits<uint32_t>::max();
    std::cout << umul(max, max) << std::endl;
    return 0;
}