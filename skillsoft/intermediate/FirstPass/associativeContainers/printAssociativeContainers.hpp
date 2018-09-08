#ifndef  __PRINT_ASSOCIATIVE_CONTAINERS_HPP__
#define  __PRINT_ASSOCIATIVE_CONTAINERS_HPP__

#include <iostream>
#include <string>

template<typename T>
void printAssociativeContainer(const T& container, std::string name)
{
    std::cout << "Elements are: " << "\n";
    for(const auto& element : container)
    {
        std::cout << "{ Key: " << element.first << ", Value: " << element.second << " }" << std::endl;
    }
    std::cout << "size of container: " << container.size() << std::endl;
    std::cout << "\n";
}

#endif // ! __PRINT_ASSOCIATIVE_CONTAINERS_HPP__
