#include "Foo.hpp"

Foo::Foo(int data):data_(data)
{
    std::cout << "constructed Foo instance: " << std::endl;
}

Foo::~Foo()
{
    std::cout << "destructed Foo instance: " << std::endl;
}

int Foo::getData() const
{
    return data_;
}