#include <iostream>
#include <typeinfo>
#include <type_traits>

/* There are 3 ways we can handle return type in templates 
 1. Adding third template parameters which specifies the RT of the template function.
 2. Let the compiler deduce the return type.
 3. Declared the return type as the common type of two parameter types*/

 template<typename T1, typename T2, typename RT>
 RT max_1(T1 lhs, T2 rhs)
 {
     return (rhs < lhs) ? lhs : rhs;
 }

 template<typename RT, typename T1, typename T2>
 RT max_2(T1 lhs, T2 rhs)
 {
     return (rhs < lhs) ? lhs : rhs;
 }

/* 2. Let the compiler deduce the return type(Below code works only with C++14 and above) */
template<typename T1, typename T2>
auto max_3(T1 lhs, T2 rhs)
{
    return (rhs < lhs) ? lhs : rhs;
}

/* works with c++11 and above */
template<typename T1, typename T2>
auto max_4(T1 lhs, T2 rhs) -> decltype(rhs < lhs ? lhs : rhs)
{
    std::cout <<"[max_4]-> Type T1: " << typeid(T1).name() << std::endl; 
    return (rhs < lhs ? lhs : rhs);
}

template<typename T1, typename T2>
auto max_5(T1 lhs, T2 rhs) -> decltype(true ? lhs : rhs)
{
    std::cout <<"[max_5]-> Type T1: " << typeid(T1).name() << std::endl; 
    return (rhs < lhs ? lhs : rhs);
}

template<typename T1, typename T2>
auto max_6(T1 lhs, T2 rhs) -> typename std::decay<decltype(true ? lhs: rhs)>::type
{
    return (rhs < lhs ? lhs : rhs);
}

/* 3. Return type as a common type */
template<typename T1, typename T2>
typename std::common_type<T1, T2>::type max_7(T1 lhs, T2 rhs)
{
    return (rhs < lhs ? lhs : rhs);
}
/* C++14 and above */
template<typename T1, typename T2>
std::common_type_t<T1, T2> max_8(T1 lhs, T2 rhs)
{
    return (rhs < lhs ? lhs : rhs);
}

int main(int argc, char* argv[])
{
    int number_1 = 10;
    double fraction_1 = 1.3;
    const int&  refToNumber_1 = number_1;
    const double& refToFraction_1 = fraction_1;

    std::cout << "max_1(3, 5.6): " << ::max_1<int, double, double>(3, 5.6) << std::endl;
    std::cout << "max_2(3, 5.6): " << ::max_2<double>(3, 5.6) << std::endl;
    std::cout << "max_3(8, 5):   " << typeid(decltype(::max_3(8, 5))).name() << std::endl;
    std::cout << "max_4(8, 5):   " << typeid(decltype(::max_4(8, 5))).name() << std::endl;
    std::cout << "max_4(8, 5):   " << ::max_4(8, 5) << std::endl;
    std::cout << "max_5(8, 5):   " << ::max_5(8, 5) << std::endl;

    std::cout << "max_5(refToNumber_1, refToFraction_1): " << ::max_5(refToNumber_1, refToFraction_1) << std::endl;
    std::cout << "max_6(refToNumber_1, refToFraction_1): " << ::max_6(refToNumber_1, refToFraction_1) << std::endl;

    std::cout << "max_7(3, 5.6): " << ::max_7(3, 5.6) << std::endl;
    std::cout << "max_8(3, 5.6): " << ::max_8(3, 5.6) << std::endl;

    return 0;
}