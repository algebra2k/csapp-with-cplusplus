#include <cstdio>
template <typename T>
class show_bytes final
{
public:
    using bytes_pointer = char *;
    show_bytes() = default;
    ~show_bytes() = default;
    void operator()(T& v) {
        _show_bytes(v);
    }

    void operator()(T&& v) {
        _show_bytes(v);
    }
private:
    void _show_bytes(T& v) {
        size_t n = sizeof(T);
        bytes_pointer ptr = reinterpret_cast<bytes_pointer>(&v);
        for(size_t i = 0; i < n; i++) {
            std::printf("%.2x", ptr[i]);
            if (i+1 != n) std::printf(" ");
        }
        std::printf("\n");  
    }
};

void show_int(int v) {
   show_bytes<int>()(v); 
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


void test_show_bytes() {
    int ival = 12345;
    float fval = ival;
    short sval = ival;
    long lval = ival;
    double dval = ival;
    show_short(sval);
    show_int(ival);
    show_long(lval);
    show_float(fval);
    show_double(dval);
}

int main()
{
    test_show_bytes();
}