#include <vector>
#include "Plane.hpp"

int main()
{
    std::vector<std::string> names;
    std::cout << "Max size of the vector names is : " << names.max_size() << std::endl;

    std::vector<Plane> planeList;
    std::cout << "Max size of the vector planeList is : " << planeList.max_size() << std::endl;

    return 0;
}