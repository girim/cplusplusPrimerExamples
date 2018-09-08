#include <map>
#include "../printAssociativeContainers.hpp"
#include "../Cone.hpp"

int main()
{
    std::map<int, char> first{{4, 'd'}, {1, 'e'}, {3, 'a'}};
    printAssociativeContainer(first, "first");

    /* find with key */
    auto iter = first.find(3);
    std::cout << "first: " << iter->first << "  ,second: " << iter->second << std::endl;

    Cone cone_1{}, cone_2{4,4,4}, cone_3{2,2,2};
    std::map<Cone, int> cones{{cone_1, 3}, {cone_2, 4}, {cone_3, 1}};

    printAssociativeContainer(cones, "cones");
    auto it = cones.find(cone_2);
    std::cout << "first " << it->first << "  ,second: " << it->second << std::endl;

    return 0;
}