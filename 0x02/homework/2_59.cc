
#include <cstdio>
#include <limits>
#include <iostream>

int generate_word(int x, int y)
{
    int magic = std::numeric_limits<int>::max() ^ 0xff; 
    return (x & 0xff) | (y & magic);
}

int main()
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int gw = generate_word(x, y);
    char *ptr = reinterpret_cast<char*>(&gw);
    for (int i = 0; i < sizeof(int);i++) {
        std::printf("%.2x\n",ptr[i]);
    }
}