#include <iostream>

template<typename... T>
auto addSum(T... s)
{
    return (... + s);
}

int main(int argc, char* argv[])
{
    addSum(1, 8, 49, 1);
    return 0;
}