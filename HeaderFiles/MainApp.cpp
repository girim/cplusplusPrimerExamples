#include <iostream>
#include "MyClass.hpp"

int main()
{
    MyClass myClassObj{};
    std::cout << "Data is: "  << myClassObj.getData() << std::endl;
    
    return 0;
}