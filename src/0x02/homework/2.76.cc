#include <cassert>
#include <iostream>

namespace csapp {
void* calloc(size_t nmemb, size_t size) {
  if (!nmemb || !size) {
    return nullptr;
  }

  size_t buf_size = nmemb * size;

  // if overflow with size_t
  if (nmemb != (buf_size / size)) {
    return nullptr;
  }

  void* mem = ::malloc(buf_size);
  if (mem == nullptr) {
    return mem;
  }

  mem = ::memset(mem, 0, buf_size);
  return mem;
}
}  // namespace csapp

void test_calloc() {
  void* p;
  p = csapp::calloc(0x1234, 1);
  assert(p != NULL);
  free(p);

  p = csapp::calloc(SIZE_MAX, 2);
  assert(p == NULL);
  free(p);
}

int main() {
  test_calloc();
  return 0;
}