#include <iostream>
#include "C.hpp"

C::C(int data): data_(data)
{
    std::cout << "constructed C:" << std::endl;
}

C::~C()
{
    std::cout << "destructed C: " << std::endl;
}

int C::getData()
{
    return data_;
}
