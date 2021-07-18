#include <cassert>
#include <cstdio>
#include <limits>

int mul3div4(int x) {
  int mul = (x << 1) + (x << 0);

  if (mul >= 0) {
    return mul >> 2;
  }

  return (x + (1 << 2) - 1) >> 2;
}

void test_mul3div4() {
  int max = std::numeric_limits<int>::max();
  int min = std::numeric_limits<int>::min();
  assert(mul3div4(255) == 255 * 3 / 4);
  assert(mul3div4(max) == max * 3 / 4);
  assert(mul3div4(min) == min * 3 / 4);
}

int main() {
  test_mul3div4();
  return 0;
}
