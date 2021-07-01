#include <iostream>
#include <cassert>
#include <limits>
#include <cstdio>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    assert(i >= 0 && i < sizeof(unsigned));
    unsigned umax = std::numeric_limits<unsigned>::max();
    assert(umax == 0xffffffff);
    // TODO implementation clear_bit
    unsigned char *ptr = reinterpret_cast<unsigned char*>(&umax);
    ptr[i] &= std::numeric_limits<unsigned>::min();
    x &= *reinterpret_cast<unsigned*>(ptr);
    // TODO implementation set_bit
    reinterpret_cast<char*>(&x)[i] |= b;
    ptr = reinterpret_cast<unsigned char*>(&x);
    return x;
}

void test_replace_byte()
{
    unsigned replaced = replace_byte(0x12345678, 2, 0xAB);
    assert(replaced == 0x12AB5678);
    replaced = replace_byte(0x12345678, 0, 0xAB);
    assert(replaced == 0x123456AB);
}

int main()
{
    test_replace_byte();
}