#ifndef CSAPP_H
#define CSAPP_H

template <typename T>
class show_bytes final
{
public:
    using bytes_pointer = char *;
    show_bytes() = default;
    ~show_bytes() = default;
    void operator()(T& v);
    void operator()(T&& v);
private:
    void _show_bytes(T& v);
};

void show_int(int v);
void show_unsigned(unsigned v);
void show_float(float v);
void show_pointer(void* v);
void show_short(float v);
void show_long(float v);
void show_double(double v);

#endif /* CSAPP_H */