#include <iostream>
#include "stacknontype.hpp"
#include "addValue.hpp"
#include <algorithm>
#include "stackauto.hpp"

int main(int argc, char *argv[])
{
    StackOne<int, 5> stk;
    stk.push(1);
    stk.push(4);
    stk.push(9);
    stk.push(8);

    std::cout << stk << "\n";

    std::cout << "Result: " << addValue<10>(6) << "\n";
    std::cout << "Result: " << addValue<10, double>(1.2) << "\n";

    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dst;

    dst.resize(src.size());

    std::transform(src.begin(), src.end(), dst.begin(), addValue<5, int>);

    for(auto element : dst)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}