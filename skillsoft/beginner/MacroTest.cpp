#include <iostream>
#define SQUARE(x) (x * x)

int main()
{
    int x = 4;
    std::cout << SQUARE(x) << std::endl;    // 4 * 4 = 16
    std::cout << SQUARE(x++) << std::endl;  // 4 * 5 = 20

    return 0;
}