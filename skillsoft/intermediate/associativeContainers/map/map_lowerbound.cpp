#include <map>
#include "../printAssociativeContainers.hpp"

int main()
{
    std::map<char, int> first{{'d', 10}, {'e', 30}, {'a', 40}, {'c',20}};
    printAssociativeContainer(first, "first");

    auto iter = first.lower_bound('e');
    auto it = first.upper_bound('d');
    auto itr = first.equal_range('c');
    std::cout << "Iter to : " << iter->first << std::endl;
    std::cout << "Iter to : " << it->first << std::endl;

    std::cout << "Equal range: Lower first: " << itr.first->first << std::endl;
    std::cout << "Equal range: Lower second: " << itr.first->second << std::endl;

    std::cout << "Equal range: Upper first: " << itr.second->first << std::endl;
    std::cout << "Equal range: Upper second: " << itr.second->second << std::endl;

    return 0;
}