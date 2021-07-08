#include <cassert>
#include <limits>
int saturating_add(int x, int y) {
  // 0xffffffff
  int mask = std::numeric_limits<int>::min();

  // calculation sum
  int sum = x + y;

  // x > 0 is replaced by !(x & mask)
  // y > 0 is replaced by !(y & mask)
  // s < 0 is replaced by (s & mask)
  // if this is true for all condtions,
  // then it means that a positive overflow.
  int pos_overflow = !(x & mask) && !(y & mask) && (sum & mask);

  // x < 0 is replaced by (x & mask)
  // y < 0 is replaced by (y & mask)
  // s > 0 is replaced by !(s & mask)
  // if this is true for all condtions,
  // then it means that a negetive overflow.
  int neg_overflow = (x & mask) && (y & mask) && !(sum & mask);

  (pos_overflow && (sum = std::numeric_limits<int>::max())) ||
      (neg_overflow && (sum = std::numeric_limits<int>::min()));

  return sum;
}

void test_saturating_add() {
    assert(saturating_add(std::numeric_limits<int>::max(), 1) == std::numeric_limits<int>::max());
    assert(saturating_add(std::numeric_limits<int>::min(), -1) == std::numeric_limits<int>::min());
    assert(saturating_add(10, 20) == 30);
}

int main() {
    test_saturating_add();
}