#include <iostream>
#include <typeinfo>
#include <type_traits>

template<typename T1, typename T2, typename RT = std::decay_t<decltype(true? T1(): T2())>>
RT max_1(T1 lhs, T2 rhs)
{
    return (rhs < lhs ? lhs : rhs);
}

template<typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT max_2(T1 lhs, T2 rhs)
{
    return (rhs < lhs ? lhs : rhs);
}

int main(int argc, char* argv[])
{
    short int shortNumber = 1;
    char number = 'b';
    std::cout << "max_1(3, 4.5): " << max_1(3, 4.5)  << " type is: " << typeid(decltype(max_1(3, 4.5))).name()<< std::endl;
    std::cout << "max_1(3, 5)  : " << max_1(3, 5)    << " type is: " << typeid(decltype(max_1(3, 5))).name() << std::endl;

    std::cout << "max_2(2, 3)  : " << max_2(2, 3)    << " type is: " << typeid(decltype(max_2(2, 3))).name() << std::endl;
    std::cout << "max_2(9, 1.0): " << max_2(9, 1.0)  << " type is: " << typeid(decltype(max_2(9, 1.0))).name() << std::endl;
    std::cout << "max_2(1, 10) : " << max_2(shortNumber, number) << "type is: " << typeid(decltype(max_2(shortNumber, number))).name() << std::endl;
    
    return 0;
}

    