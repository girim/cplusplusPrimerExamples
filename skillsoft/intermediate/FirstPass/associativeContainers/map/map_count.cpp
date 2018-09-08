#include <map>
#include "../printAssociativeContainers.hpp"

int main()
{
    std::map<int, std::string> table{{3, "RCB"}, {4, "CSK"}, {1, "SRH"}};
    printAssociativeContainer(table, "table");

    std::cout << "No of keys : " << table.count(4) << std::endl;
    std::cout << "No of keys : " << table.count(2) << std::endl;

    return 0;
}
