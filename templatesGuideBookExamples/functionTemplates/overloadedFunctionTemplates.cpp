#include <iostream>
#include <typeinfo>

/* Non-Template function */
int max(int x, int y)
{
    std::cout << "max(int, int) called .... " << std::endl;
    return (y < x ? x : y);
}

/* Template function */
template<typename T>
T max(T x, T y)
{
    std::cout << "max(T, T) called with type:  "<< typeid(T).name() << std::endl;
    return (y < x ? x : y);
}

template<typename T1, typename T2>
auto max_1(T1 lhs, T2 rhs)
{
    std::cout << "max_1(T1, T2): " << std::endl;
    return (rhs < lhs ? lhs : rhs);
}

template<typename RT, typename T1, typename T2>
RT max_1(T1 lhs, T2 rhs)
{
    std::cout << "max_1(RT, T1, T2): " << std::endl;
    return (rhs < lhs ? lhs : rhs);
}

int main(int argc, char* argv[])
{
    max(10, 20);
    max(10.3, 39.9);
    max<>(1, 8);
    max('c', 'd');
    max('c', 10);   //Templates does not allow type conversion

    max_1(4, 6.7);
    //max_1<double>(7.8, 9);   //Ambiguous call
    //max_1<int>(4, 7.2);

    return 0;
}