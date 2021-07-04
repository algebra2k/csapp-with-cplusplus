#include <cassert>

unsigned fill_leftmost_by_leftmost(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x;
}

/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
* If x = 0, then return 0.
*/
int leftmost_one(unsigned x)
{
    /*
   * First, generate a mask that all bits after leftmost one are one
   * e.g. 0xFF00 -> 0xFFFF, and 0x6000 -> 0x7FFF
   * If x = 0, get 0
   */
    x = fill_leftmost_by_leftmost(x);
    /* 
    * Then, x>>1 eliminates the highest 1. x&1 retains the lowest bit of 1;
    * (x>>1) + (x&1) The addition operation rounds to the nearest bit
    *   1. because all bits after the highest bit of x are 1
    *   2. and because x>>1 eliminates the highest bit
    *   3. so the result is all zeros after the highest bit eliminated
    */
    return  (x>>1) + (x&1); 
}


int main()
{
    assert(leftmost_one(0x6000) == 0x4000);
    return 0;
}
#include <cassert>

unsigned generate_leftmost_after_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x;
}

/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
* If x = 0, then return 0.
*/
int leftmost_one(unsigned x)
{
    /*
   * First, generate a mask that all bits after leftmost one are one
   * e.g. 0xFF00 -> 0xFFFF, and 0x6000 -> 0x7FFF
   * If x = 0, get 0
   */
    x = generate_leftmost_after_one(x);
    /* 
    * Then, x>>1 eliminates the highest 1. x&1 retains the lowest bit of 1;
    * (x>>1) + (x&1) The addition operation rounds to the nearest bit
    *   1. because all bits after the highest bit of x are 1
    *   2. and because x>>1 eliminates the highest bit
    *   3. so the result is all zeros after the highest bit eliminated
    */
    return  (x>>1) + (x&1); 
}


int main()
{
    assert(leftmost_one(0x6000) == 0x4000);
    return 0;
}
