#include "csapp.h"
#include <cstdio>

template <typename T>
void show_bytes<T>::operator()(T& v) {
    _show_bytes(v);
}

template <typename T>
void show_bytes<T>::operator()(T&& v) {
    _show_bytes(v);
}

template <typename T>
void show_bytes<T>::_show_bytes(T& v) {
    size_t n = sizeof(T);
    bytes_pointer ptr = reinterpret_cast<bytes_pointer>(&v);
    for(size_t i = 0; i < n; i++) {
        std::printf("%.2x", ptr[i]);
        if (i+1 != n) std::printf(" ");
    }
    std::printf("\n");  
}

void show_int(int v) {
   show_bytes<int>()(v); 
}

void show_unsigned(unsigned v) {
   show_bytes<unsigned>()(v); 
}
void show_float(float v) {
   show_bytes<float>()(v); 
}

void show_pointer(void* v) {
   show_bytes<void*>()(v); 
}

void show_short(float v) {
   show_bytes<short>()(v); 
}

void show_long(float v) {
   show_bytes<long>()(v); 
}

void show_double(double v) {
    show_bytes<double>()(v);
}