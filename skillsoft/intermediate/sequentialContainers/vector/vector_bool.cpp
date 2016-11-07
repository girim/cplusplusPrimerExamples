#include <vector>
#include "printVectorContents.hpp"

int main()
{
    std::vector<bool> bits;
    bits.push_back(true);
    bits.push_back(false);
    bits.push_back(true);
    bits.push_back(false);

    printVectorContents(bits, "bits_1");
    std::cout << "\n";

    bits.flip();
    printVectorContents(bits, "bits_1");

    return 0;
}