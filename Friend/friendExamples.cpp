#include <iostream>
#include "Foo.hpp"

void someFunc()
{
    Foo foo{2};
    std::cout << "Value of foo: " << foo.getData() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Foo& foo)
{
    os <<"Printing Foo contents: " << foo.getData();
    return os; 
}

void NonMemberFunction();

int main()
{
    Foo foo1{};
    Foo foo2{4};
    someFunc();
    std::cout << foo2 << std::endl;
    Bar bar{6};
    bar.combineDataFromFooAndBar(foo2);
    NonMemberFunction();
    return 0;
}

