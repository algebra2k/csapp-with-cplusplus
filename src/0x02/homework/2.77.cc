#include <cassert>
#include <cstdio>

// when K = 17, do x * 17
int mul_17(int x) {
  // 17 = b 0001 0001
  return (x << 4) + (x << 0);
}

int mul_7(int x) {
  // 7 = 0000 0111
  // n = 2, m = 0
  int n = 2, m = 0;
  return (x << (n + 1)) - (x << m);
}

// when K = -7, do x * -7
int mul_neg_7(int x) { return ~((x << 3) - (x << 0)) + 1; }

// when K = 60, do x * 60
int mul_60(int x) {
  // 60 = b 0011 1100
  // n = 5, m = 2
  int n = 5, m = 2;
  return (x << (n + 1)) - (x << m);
}

// when K = -112, do x * -112
int mul_neg_112(int x) {
  // b 112 = 0111 0000
  // n = 6, m = 4
  int n = 6, m = 4;
  return ~((x << (n + 1)) - (x << m)) + 1;
}

int mul_k(int x, int k) {
  switch (k) {
    case 17:
      return mul_17(x);
    case -7:
      return mul_neg_7(x);
    case 60:
      return mul_60(x);
    case -112:
      return mul_neg_112(x);
    default:
      return x;
  }
}

void test_mul_k() {
  std::printf("%d\n", mul_k(10, 17));
  std::printf("%d\n", mul_k(13, -7));
  std::printf("%d\n", mul_k(10, 60));
  std::printf("%d\n", mul_k(10, -112));
}

int main() { test_mul_k(); }
