#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>

//call-by-refrence
template<typename T>
T const& max(T const& lhs, T const& rhs)
{
    std::cout << "maximum of two values of any type: " << typeid(T).name() << \
        " lhs : "<< lhs  << " rhs: " << rhs << std::endl;

    return (rhs < lhs ? lhs : rhs);
}

//call-by-value
char const* max(char const* lhs, char const* rhs)
{
    std::cout << "maximum of two c-strings: " << " lhs: " << &lhs << " rhs: " << &rhs << std::endl;
    return (std::strcmp(rhs, lhs) < 0 ? lhs : rhs);
}

//call-by-reference
template<typename T>
T const& max(T const& a, T const& b, T const& c)
{
    std::cout << "[max3]: value of a: " << &a << " value of b: " << &b << std::endl; 
    std::cout << "maximum of three values of any type: " << typeid(T).name() << std::endl;
    return max(a, b);
    //return max(max(a, b), c);
}

int main()
{
    //auto m1 = ::max(2, 4, 5);
    char const* str1 = "fredric";
    char const* str2 = "anica";
    char const* str3 = "lucas";

    auto m2 = ::max(str1, str2, str3);

    return 0;
}