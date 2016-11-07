#ifndef __PRINT_VECTOR_CONTENTS__
#define __PRINT_VECTOR_CONTENTS__

#include <iostream>
#include <string> 

template<typename T>
void printVectorContents(const T& vec, std::string name)
{
    for(const auto& element : vec)
        std::cout << "Element of " << name << " is: " << element << std::endl;
}


#endif //__PRINT_VECTOR_CONTENTS__