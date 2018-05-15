#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>

template<typename T>
T max(T lhs, T rhs)
{
    std::cout << "maximum of two values of any type: T = " << typeid(T).name() << " ";
    return (rhs < lhs ?  lhs : rhs);
}

template<typename T>
T* max(T* lhs, T* rhs)
{
    std::cout << "maximum of two pointers: T = " << typeid(T).name() << " ";
    return (*rhs < *lhs ? lhs : rhs);
}

const char* max(const char* lhs, const char* rhs)
{
    std::cout << "maximum of two C-strings: T = const char* " << " ";
    return std::strcmp(rhs, lhs) < 0 ? lhs : rhs;
}

int main(int argc, char* argv[])
{
    int x = 4, y = 7;
    float a = 5.1f, b = 6.7f;
    int *ptr_1 = &x;
    int *ptr_2 = &y;
    const char* cplusplus = "cplusplus";
    const char* java = "java";
    std::string text_1 = "text_1";
    std::string text_2 = "text_2";

    std::cout << ", max is: " << ::max(x, y) << "\n";
    std::cout << ", max is: " << ::max(a, b) << "\n";
    std::cout << ", max is: " << *(::max(ptr_1, ptr_2)) << "\n";
    std::cout << ", max is: " << ::max(cplusplus, java) << "\n";
    std::cout << ", max is: " << ::max(text_1, text_2)  << "\n";
    
    return 0;
}
