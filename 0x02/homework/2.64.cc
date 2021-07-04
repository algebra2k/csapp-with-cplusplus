#include <cassert>
#include <iostream>

/* Return 1 when any odd bit of x equals; 0 otherwise.
   Assume w=32
*/
int any_odd_one(unsigned x)
{
    unsigned all_odd_bit = 0xaaaaaaaa;
    return !!(all_odd_bit & x);
}

void test_any_odd_one()
{
    assert(any_odd_one(0x2) == 1);
    assert(any_odd_one(0x4) == 0);
    assert(any_odd_one(0xAAAAAAAA) == 1);
    assert(any_odd_one(0x55555555) == 0);
}

int main()
{
    test_any_odd_one();
}