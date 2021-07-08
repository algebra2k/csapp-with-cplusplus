#include <cassert>
#include <limits>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y) {
  int ok = 1;

  int negy = -y;
  int sum = x + negy;

  int pos_overflow = x > 0 && negy > 0 && sum < 0;
  int neg_overflow = x < 0 && negy < 0 && sum > 0;

  ok = !(pos_overflow || neg_overflow);

  return ok;
}

void test_tsub_ok() {
  int int_min = std::numeric_limits<int>::min();
  int int_max = std::numeric_limits<int>::max();
  assert(tsub_ok(int_min, 1) == 0);
  assert(tsub_ok(int_max, -2) == 0);
  assert(tsub_ok(int_max, int_min) == 1);
  assert(tsub_ok(10, 10) == 1);
  assert(tsub_ok(int_min, 0) == 1);
  assert(tsub_ok(0, 0) == 1);
}

int main() { test_tsub_ok(); }