#ifndef __PRINT_SET_CONTENTS_HPP__
#define __PRINT_SET_CONTENTS_HPP__

template<typename T>
void printSetContents(const T& container, std::string name)
{
    std::cout << "Elements of " << name << " are: ,"
    for(const auto& element : container)
    {
        std::cout << "key/value: " << element << std::endl;
    }
    std::cout << "\n";
}

#endif //!__PRINT_SET_CONTENTS_HPP__