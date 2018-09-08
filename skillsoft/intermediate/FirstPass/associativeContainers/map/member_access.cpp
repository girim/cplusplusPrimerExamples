#include <map>
#include "../printAssociativeContainers.hpp"


int main() 
{
    /* 1. subscript operator [] --> does not throw out_of_range exception if key is out of bound */
    std::map<std::string, int> pointsTable;
    pointsTable["CSK"] = 10;   //returns lvalue reference
    pointsTable["SRH"] = 12;
    pointsTable["DD"]  = 8;
    pointsTable["KKR"] = 6;
    pointsTable["MI"]; //assigns some default value with provided key

    printAssociativeContainer(pointsTable, "pointsTable");

    std::cout << "Value at key MI is : " << pointsTable["MI"] << std::endl;
    pointsTable["MI"] = 5;
    printAssociativeContainer(pointsTable, "pointsTable");

    /* 2. at --> equvalent to [] but throws out_of_range exception if key is out of bound */
    std::map<int, std::string> teams = {{1, "RCB"}, {4, "DD"}, {2, "RR"}, {5, "KXIP"}};
    printAssociativeContainer(teams, "teams");

    try{
        teams.at(3) = "SRH";
    }
    catch(std::out_of_range& error)
    {
        std::cout << "Team not found: " << error.what() << std::endl;
    }

    teams.at(2) = "SRH";
    printAssociativeContainer(teams, "teams");

    return 0;
}