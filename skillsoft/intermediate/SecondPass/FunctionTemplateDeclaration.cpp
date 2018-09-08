#include <iostream>

template<typename T>
T inline maxOfTwo(const T& lhs, const T& rhs)
{
    return (lhs > rhs) ? lhs : rhs;
};

int main(int argc, char const *argv[])
{
    unsigned x = 28, y = 60;
    std::cout << "maxOfTwo(28, 60): " << maxOfTwo(28, 60) << "\n";
    std::cout << "maxOfTwo(28, 60): " << maxOfTwo<unsigned>(28, 60) << "\n";

    double a = 19.88, b = 19.87;
    std::cout << "maxOfTwo(19.88, 19.87): " << maxOfTwo(a, b) << "\n";

    std::string m = "C++", n = "JavaScript";
    std::cout << "maxOfTwo(C++, JavaScript): " << maxOfTwo(m, n) << "\n";

    return 0;
}
