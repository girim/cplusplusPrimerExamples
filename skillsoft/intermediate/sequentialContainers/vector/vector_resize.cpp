#include <vector>
#include <string>
#include "Plane.hpp"
#include "printVectorContents.hpp"

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "{ length: " << plane.getLength() <<  " width: " << plane.getWidth() \
        << " Area: " << plane.getAreaOfPlane() << " }";

    return os;
}

int main()
{
    std::vector<std::string> teams{"RCB", "CSK", "DD", "KKR", "RR", "SRH"};
    std::cout << "Size of teams: " << teams.size() << " Capacity: " << teams.capacity() << std::endl;
    printVectorContents(teams, "teams_1");

    teams.resize(4);
    std::cout << "Size of teams: " << teams.size() << " Capacity: " << teams.capacity() << std::endl;
    printVectorContents(teams, "teams_2");

    teams.resize(8, "TBD");
    std::cout << "Size of teams: " << teams.size() << " Capacity: " << teams.capacity() << std::endl;
    printVectorContents(teams, "teams_3");

    Plane p1{}, p2{};
    std::vector<Plane> planeList{p1, p2};
    std::cout << "Size of planeList: " << planeList.size() << " Capacity: " << planeList.capacity() << std::endl;
    printVectorContents(planeList, "teams_4");

    planeList.resize(1);
    std::cout << "Size of planeList: " << planeList.size() << " Capacity: " << planeList.capacity() << std::endl;
    printVectorContents(planeList, "teams_5");

    return 0;
}
