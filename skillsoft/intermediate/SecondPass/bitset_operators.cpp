#include <iostream>
#include <bitset>

int main(int argc, char const *argv[])
{
    const int N = 16;
    std::bitset<N> x{163};
    std::bitset<N> y{143};

    std::cout << "x: " << x << "\n";
    std::cout << "y: " << y << "\n";

    /* operators */

    /* Bitwise AND */
    std::bitset andResult =  x & y;
    std::cout << "andResult: " << andResult << "\n";

    /* Bitwise OR */
    std::bitset orResult =  x | y;
    std::cout << "orResult: " << orResult << "\n";

    /* Bitwise XOR */
    std::bitset xorResult =  x ^ y;
    std::cout << "xorResult: " << xorResult << "\n";

    /* Left shift */
    std::cout << "LeftShift x: " << (x << 2) << "\n";

    /* Right shift */
    std::cout << "RightShift y: " << (y >> 1) << "\n";

    /* Nagate */
    std::cout << "Negate y: " << ~y << "\n";
    
    /* Compound AND */
    x&=y;
    std::cout << "x: " << x << "\n";

    /* Compound OR */
    x|=y;
    std::cout << "x: " << x << "\n";

    /* Compound XOR */
    x^=y;
    std::cout << "x: " << x << "\n";

    y<<=2;
    std::cout << "y: " << y << "\n";

    y>>=3;
    std::cout << "y: " << y << "\n";

    return 0;
}
