#include <bit>
#include <iostream>
#include <cstdio>

bool is_little_ending()
{
    char one = 1U;
    return reinterpret_cast<char*>(&one)[sizeof(char) - 1] - 1 == -1;
}


void test_is_little_ending() 
{

    std::cout << "is little ending: " <<  is_little_ending() << std::endl;
}


int main()
{
    test_is_little_ending();
}