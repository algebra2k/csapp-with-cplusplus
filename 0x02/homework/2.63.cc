#include <cassert>
#include <iostream>

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = static_cast<int>(x) >> k;

    // calculate w
    int w = sizeof(int) * 8;

    // calculate remain
    int remain = w - k;

    return xsra & ~(0xffffffff << remain);
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = static_cast<unsigned>(x) >> k;

    // calculate w
    int w = sizeof(int) * 8;

    // calculate remain
    int remain = w - k;

    // calculate mask 
    int mask = 0xffffffff << remain;

    // get x highest bit
    int x_highest = x & 0x80000000;

    // if x_highest = 1, then x_highest_r = -1 = 0xffffffff; 
    // if x_highest = 0, then x_highest_r =  0 = 0x00000000; 
    int x_highest_r = !x_highest - 1;

    // calculating reverse bits of mask.
    // if x_highest = 1, then mask = 0xff000000 and mask & x_highest_r = 0xff000000;
    // if x_highest = 0, then mask = 0xff000000 and mask & x_highest_r = 0x00000000;
    mask = mask & x_highest_r;

    // restore shift arithmetic bits 
    return xsrl | mask;
}


void test_srl()
{
    unsigned x1 = 0x12345678;
    unsigned x2 = 0x87654321;
    assert(srl(x1, 4) == (x1 >> 4));
    assert(srl(x2, 4) == (x2 >> 4));
}

void test_sra()
{
    int x1 = 0x12345678;
    int x2 = 0x87654321;
    assert(sra(x1, 4) == x1 >> 4);
    assert(sra(x2, 4) == x2 >> 4);
}

int main()
{
    test_srl();
    test_sra();
}


