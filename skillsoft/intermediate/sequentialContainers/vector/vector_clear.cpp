#include <vector>
#include "printVectorContents.hpp"
#include "Plane.hpp"

int main()
{
    std::vector<int> offsets{3, 6, 9};
    printVectorContents(offsets, "offsets");
    std::cout <<"size of offsets before clearing the contents: " << offsets.size() << std::endl;
    std::cout <<"capacity of offsets before clearing the contents: " << offsets.capacity() << std::endl;

    offsets.clear();
    printVectorContents(offsets, "offsets");

    std::cout <<"size of offsets after clearing the contents: " << offsets.size() << std::endl;
    std::cout <<"capacity of offsets after clearing the contents: " << offsets.capacity() << std::endl;

    return 0;
}