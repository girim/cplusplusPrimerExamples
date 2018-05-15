
#define NDEBUG
#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
    int denominator = 0;
    float result;

    while(denominator != 100)
    {
        std::cout << "Enter the denominator: " << "\n";
        std::cin >> denominator;

        assert(denominator != 0);

        result += 100/denominator;
        std::cout << "Result is now: " << result << "\n";
    }
    return 0;
}


