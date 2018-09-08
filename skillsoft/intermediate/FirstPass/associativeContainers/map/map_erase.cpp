#include <map>
#include <iostream>
#include "../printAssociativeContainers.hpp"

int main()
{
    std::map<std::string, int> pointsTable;
    pointsTable.insert({"RCB", 3});
    pointsTable.insert(std::pair<std::string, int>("KKR", 5));
    pointsTable.insert(std::make_pair<std::string, int>("SRH", 2));
    pointsTable.insert({"CSK", 7});
    pointsTable.insert({"KXIP", 10});
    pointsTable.insert({"DD", 12});

    printAssociativeContainer(pointsTable, "pointsTable");

    /* 1. erase using the Key */
    pointsTable.erase("DD");
    printAssociativeContainer(pointsTable, "pointsTable");

    /* 2. erase using the position */
    auto iter = pointsTable.begin();
    ++iter;
    pointsTable.erase(iter);
    printAssociativeContainer(pointsTable, "pointsTable");

    /* 3. erase using the range */
    iter = ++pointsTable.begin();
    pointsTable.erase(pointsTable.begin(), ++iter);
    printAssociativeContainer(pointsTable, "pointsTable");

    return 0;
}