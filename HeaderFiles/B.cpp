#include <iostream>
#include "B.hpp"

B::B(int data): data_(data)
{
    std::cout << "constructed B: " << std::endl;
}

B::~B()
{
    std::cout << "destructed B: " << std::endl;
}

int B::getData()
{
    return data_;
}