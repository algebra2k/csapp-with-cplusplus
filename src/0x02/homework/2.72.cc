#include <cstdlib>
#include <cstring>
#include <iostream>

void copy_int(int val, void* buf, int maxbytes) {
  if (maxbytes < sizeof(int)) {
    return;
  }

  if (maxbytes - sizeof(int) >= 0) {
    std::memcpy(buf, &val, sizeof(int));
  };
}

void test_copy_int() {
  int val = 0x7FFFFFFF;
  char enough_buf[sizeof(int)];
  copy_int(val, enough_buf, sizeof(int));
  assert(*reinterpret_cast<int*>(enough_buf) == val);

  char short_buf[sizeof(short)];
  copy_int(val, short_buf, sizeof(short));
  assert(*reinterpret_cast<int*>(short_buf) != val);

  char zero_buf[0];
  copy_int(val, zero_buf, 0);
  assert(*reinterpret_cast<int*>(zero_buf) != val);
}

int main() { test_copy_int(); }