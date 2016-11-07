#include <iostream>
#include "A.hpp"

A::A(B &refToB, B *ptrToB, int data) : refToB_(refToB), ptrToB_(ptrToB), data_(data)
{
    std::cout << "Constructed A: " << std::endl;
}

A::~A()
{
    std::cout << "Destructed A: " << std::endl;
}

B& A::someFunc(B& b)
{
    return b;
}

B* A::someFunc(B* b)
{
    return b;
}

int A::getData()
{
    return data_;
}