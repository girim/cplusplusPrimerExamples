#include <map>
#include "../printAssociativeContainers.hpp"

int main()
{
    std::map<std::string, int> pointsTable;
    pointsTable.insert({"CSK", 4});
    pointsTable.insert({"RCB", 2});
    pointsTable.insert({"SRH", 1});
    pointsTable.insert({"KIXP",3});

    /* begin, end */
    for(std::map<std::string, int>::iterator iter = pointsTable.begin(); iter != pointsTable.end(); ++iter)
    {
        std::cout << "Key: " << iter->first << " ,Value: " << iter->second << std::endl;
        if (iter->first == "KIXP")
        {
            iter->second = 0;
        }
    }
    std::cout << "\n";

    /* rbegin, rend */
    for(std::map<std::string, int>::reverse_iterator iter = pointsTable.rbegin(); iter != pointsTable.rend(); ++iter)
    {
        std::cout << "Key: " << iter->first << " ,Value: " << iter->second << std::endl;
    }
    std::cout << "\n";
    
    /* cbegin, cend */
    for(std::map<std::string, int>::const_iterator iter =  pointsTable.cbegin(); iter != pointsTable.cend(); ++iter)
    {
        std::cout << "Key: " << iter->first << " ,Value: " << iter->second << std::endl;
    }
    std::cout << "\n";

    /* crbegin, crend */
    for(std::map<std::string, int>::const_reverse_iterator iter = pointsTable.crbegin(); iter !=pointsTable.crend(); ++iter)
    {
        std::cout << "Key: " << iter->first << " ,Value: " << iter->second << std::endl; 
    }

    return 0;
}