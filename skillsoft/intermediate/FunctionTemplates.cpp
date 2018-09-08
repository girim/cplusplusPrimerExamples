#include <iostream>

template<typename T>
inline T maxOfTwo(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

inline const char* maxOfTwo(const char* lhs, const char* rhs)
{
    return *lhs < *rhs ? rhs : lhs;
}

int main(int argc, char const *argv[])
{
    std::cout << "maxOfTwo(1, 3): " << maxOfTwo(1, 3) << std::endl;
    std::cout << "maxOfTwo(50.2323, 20.9): " << maxOfTwo(50.2323, 20.9) << std::endl;
    std::cout << "maxOfTwo(hello, js): " << maxOfTwo("hello", "js") << std::endl;
   
    return 0;
}
