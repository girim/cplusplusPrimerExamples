#include <iostream>

const char* test(const char* a)
{
    return a;
}

template<typename T>
int someFunc(T const &b)
{
    auto c = test(b);
    std::cout << c << std::endl;
    return 0;
}

int main(int argc, char * argv[])
{ 
    const char* str = "hello";
    std::cout << someFunc(str) << std::endl;

    return 0;
}