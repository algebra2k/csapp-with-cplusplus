#include <cassert>
#include <cstdio>

/* Divide by power of 2. Assume 0 <=k < w-1 */
int divide_power2(int x, int k) {
  if (x >= 0) {
    return x >> k;
  }

  // get k power of 2
  int y = 1 << k;
  return (x + y - 1) >> k;
}

void test_divide_power2() {
  assert(divide_power2(255, 4) == 255 / (1 << 4));
  assert(divide_power2(-255, 4) == -255 / (1 << 4));
}

int main() { test_divide_power2(); }
