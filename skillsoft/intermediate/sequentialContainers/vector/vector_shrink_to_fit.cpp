#include <vector>
#include <string>
#include <iostream>
#include "Plane.hpp"

int main()
{
    std::vector<int> intergers(40);
    std::cout << "size is : " << intergers.size() << " capacity: " << intergers.capacity() << std::endl;

    intergers.resize(30);
    std::cout << "size is : " << intergers.size() << " capacity: " << intergers.capacity() << std::endl;
    
    intergers.shrink_to_fit();
    std::cout << "size is : " << intergers.size() << " capacity: " << intergers.capacity() << std::endl;

    return 0;
}