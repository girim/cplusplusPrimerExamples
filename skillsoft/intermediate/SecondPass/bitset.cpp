#include <iostream>
#include <bitset>

const int N = 16;

int main(int argc, char const *argv[])
{
    /* construction */
    /* 1. default constructor */
    std::bitset<N> zeros{};
    std::cout << "zeros: " << zeros << "\n";

    /* 2. using an integer */
    std::bitset<N> number{77};
    std::bitset<N> hexNumber{0xffe};
    std::cout << "number: " << number << "\n";
    std::cout << "hexNumber: " << hexNumber << "\n";

    /* 3. using Binary String */
    std::bitset<N> binaryString{"101010"};
    std::cout << "binaryString: " << binaryString << "\n";

    try
    {
         std::bitset<N> str{"1040a10"};
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
