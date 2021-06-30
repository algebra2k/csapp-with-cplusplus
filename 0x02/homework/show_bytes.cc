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
