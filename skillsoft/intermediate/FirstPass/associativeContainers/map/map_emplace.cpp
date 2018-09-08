#include <map>
#include "../printAssociativeContainers.hpp"
#include "../Cone.hpp"

int main()
{
    std::map<Cone, int> cones;
    cones.emplace(std::piecewise_construct, std::make_tuple(4,4,4), std::make_tuple(3));
    cones.emplace(std::piecewise_construct, std::make_tuple(6,7,8), std::make_tuple(5));
    cones.emplace(std::piecewise_construct, std::make_tuple(2,2,2), std::make_tuple(60));
    auto iter = cones.emplace(std::piecewise_construct, std::make_tuple(1,1,1), std::make_tuple(10));

    std::cout << "First->first:  " << iter.first->first << " ,First->second: " << iter.first->second << std::endl;
    std::cout << "Second: " << iter.second << std::endl;

    printAssociativeContainer(cones, "cones");

    return 0;
}