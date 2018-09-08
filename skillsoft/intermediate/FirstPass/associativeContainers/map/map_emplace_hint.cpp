#include <map>
#include "../printAssociativeContainers.hpp"
#include "../Cone.hpp"

int main()
{
    std::map<int, Cone> cones;
    auto iter = cones.emplace_hint(cones.begin(), std::piecewise_construct, std::make_tuple(2), std::make_tuple());
    iter = cones.emplace_hint(iter, std::piecewise_construct, std::make_tuple(1), std::make_tuple(0));
    iter = cones.emplace_hint(iter, std::piecewise_construct, std::make_tuple(5), std::make_tuple(3, 4));
    cones.emplace_hint(iter, std::piecewise_construct, std::make_tuple(4), std::make_tuple(6, 1, 9));

    printAssociativeContainer(cones, "cones");

    return 0;
}