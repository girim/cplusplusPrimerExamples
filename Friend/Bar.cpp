#include <iostream>
#include "Foo.hpp"

Bar::Bar(double data): data_(data)
{
    std::cout << "constructed Bar: " << std::endl;
}

Bar::~Bar()
{
    std::cout << "destructed Bar: " << std::endl;
}

double Bar::getData()
{
    return data_;
}

void Bar::combineDataFromFooAndBar(Foo &foo)
{
    std::cout <<"Data From Foo is: " << foo.getData() << std::endl;
}