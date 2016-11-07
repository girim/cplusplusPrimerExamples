#ifndef __PRINT_VECTOR_CONTENTS__
#define __PRINT_VECTOR_CONTENTS__

#include <iostream>
#include <string> 

void drawBorderLines(std::size_t size)
{
    for(auto index = 0; index < size; ++index)
        std::cout << "-------";
    std::cout << "\n";
}

template<typename T>
void printContainerContents(const T& container, std::string name)
{
    std::cout << "Element of " << name << " is: " << std::endl;

    //drawBorderLines(container.size());
    std::cout << "| ";
    for(const auto& element : container)
    {
        std::cout << element << " | ";
    } 
    std::cout << "\n";
    //drawBorderLines(container.size());
    std::cout << std::endl;
}



#endif //__PRINT_VECTOR_CONTENTS__
