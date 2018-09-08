#include <iostream>
#include <bitset>

int main(int argc, char const *argv[])
{
    const int N = 16;
    std::bitset<N> bits{4095};
    std::cout << "bits: " << bits << "\n";

    /* Using [] operator */
    bits[7] = 0;
    bits[14] = 1;
    bits[15] = 1;
    std::cout << "bits: " << bits << "\n";

    /* count --> counts the number of bits set to '1' */
    std::cout << "No of bits set to 1 are: " << bits.count() << "\n";

    /* size --> counts the number of bits (both 0s and 1s) */
    std::cout << "Size : " << bits.size() << "\n";

    /* How to find no of '0's */
    std::cout << "No of bits set to 0 are: " << (bits.size() - bits.count()) << "\n";

    /* test --> Equvalent of [] but throws out_of_range exception*/
    std::cout << "bit at position 4 is : " << bits.test(3) << "\n";
    std::cout << "bit at position 7 is : " << bits.test(7) << "\n";

    try
    {
        bits.test(17);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* any --> checks if any bit is set */
    std::cout << "Is any bit set? " << bits.any() << "\n";

    /* none --> returns true if none of the bits are set */
    std::cout << "Is none set? " << bits.none() << "\n";

    /* all --> returns true if all bits are set */
    std::cout << "bits: " << bits << "\n";
    bits.set();
    std::cout << "Is all set? " << bits.all() << "\n";

    bits.reset();
    std::cout << "Is none set? " << bits.none() << "\n";

    bits[4] = 1;
    bits[8] = 1;
    bits[13] = 1;
    std::cout << "bits: " << bits << "\n";

    bits.flip();
    std::cout << "bits: " << bits << "\n";


    return 0;
}
